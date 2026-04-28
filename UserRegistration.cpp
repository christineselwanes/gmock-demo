#include "UserRegistration.hpp"

UserRegistration::UserRegistration(EmailService* service) : service(service) {}

bool UserRegistration::registerUser(const std::string& name, const std::string& email) { return service->sendEmail(email, "Welcome", "Hello " + name); }