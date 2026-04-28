#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "UserRegistration.hpp"

using ::testing::Return;
using ::testing::StrEq;

class MockEmailService : public EmailService {
 public:
  MOCK_METHOD(bool, sendEmail, (const std::string& to, const std::string& subject, const std::string& body), (override));
};

TEST(UserRegistrationTest, SendsWelcomeEmail) {
  MockEmailService mock;
  UserRegistration reg(&mock);

  EXPECT_CALL(mock, sendEmail(StrEq("ali@test.com"), StrEq("Welcome"), StrEq("Hello Ali"))).WillOnce(Return(true));

  EXPECT_TRUE(reg.registerUser("Ali", "ali@test.com"));
}

TEST(UserRegistrationTest, ReturnsFalseWhenEmailFails) {
  MockEmailService mock;
  UserRegistration reg(&mock);

  EXPECT_CALL(mock, sendEmail(StrEq("bob@test.com"), StrEq("Welcome"), StrEq("Hello Bob"))).WillOnce(Return(false));

  EXPECT_FALSE(reg.registerUser("Bob", "bob@test.com"));
}
TEST(UserRegistrationTest, SendsCorrectEmailToMultipleUsers) {
    MockEmailService mock;
    UserRegistration reg(&mock);

    EXPECT_CALL(mock, sendEmail(StrEq("sara@test.com"), StrEq("Welcome"), StrEq("Hello Sara"))).WillOnce(Return(true));

    EXPECT_TRUE(reg.registerUser("Sara", "sara@test.com"));
}
