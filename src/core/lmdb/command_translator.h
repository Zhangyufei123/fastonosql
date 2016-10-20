/*  Copyright (C) 2014-2016 FastoGT. All right reserved.

    This file is part of FastoNoSQL.

    FastoNoSQL is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FastoNoSQL is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FastoNoSQL.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <string>  // for string

#include <common/error.h>  // for Error
#include <common/value.h>  // for Value, Value::Type

#include "core/db_key.h"                          // for NDbKValue, NKey, ttl_t
#include "core/translator/icommand_translator.h"  // for ICommandTranslator

namespace fastonosql {
namespace core {
namespace lmdb {
class CommandTranslator : public ICommandTranslator {
 public:
  CommandTranslator();

 private:
  virtual common::Error createKeyCommandImpl(const NDbKValue& key,
                                             std::string* cmdstring) const override;
  virtual common::Error loadKeyCommandImpl(const NKey& key,
                                           common::Value::Type type,
                                           std::string* cmdstring) const override;
  virtual common::Error deleteKeyCommandImpl(const NKey& key,
                                             std::string* cmdstring) const override;
  virtual common::Error renameKeyCommandImpl(const NKey& key,
                                             const std::string& new_name,
                                             std::string* cmdstring) const override;
  virtual common::Error changeKeyTTLCommandImpl(const NKey& key,
                                                ttl_t ttl,
                                                std::string* cmdstring) const override;
};
}
}  // namespace core
}  // namespace fastonosql