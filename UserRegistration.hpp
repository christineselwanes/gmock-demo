#pragma once

#include <string>

#include "EmailService.hpp"

class UserRegistration {
 public:
  explicit UserRegistration(EmailService* service);

  bool registerUser(const std::string& name, const std::string& email);

 private:
  EmailService* service;
};
