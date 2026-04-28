#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "UserRegistration.hpp"

using ::testing::Return;
using ::testing::StrEq;

class MockEmailService : public EmailService {
 public:
  MOCK_METHOD(bool, sendEmail, (const std::string& email, const std::string& message), (override));
};

TEST(UserRegistrationTest, SendsWelcomeEmail) {
  MockEmailService mock;

  UserRegistration reg(&mock);

  EXPECT_CALL(mock, sendEmail(StrEq("ali@test.com"), StrEq("Welcome Ali"))).WillOnce(Return(true));

  EXPECT_TRUE(reg.registerUser("Ali", "ali@test.com"));
}
