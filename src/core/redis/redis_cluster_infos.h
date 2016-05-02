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

#include <hiredis/hiredis.h>

#include "core/types.h"

namespace fastonosql {
namespace core {
namespace redis {

class RedisDiscoveryInfo
  : public ServerDiscoveryClusterInfo {
 public:
  RedisDiscoveryInfo(const ServerCommonInfo& info, bool self);

  std::string hash() const;
  void setHash(const std::string& hash);

 private:
  std::string hash_;
};

ServerDiscoveryClusterInfo* makeOwnRedisDiscoveryInfo(const std::string& text);
common::Error makeDiscoveryClusterInfo(const common::net::hostAndPort& parentHost,
                                   const std::string& text,
                                   std::vector<ServerDiscoveryClusterInfoSPtr>* infos);

}  // namespace redis
}  // namespace core
}  // namespace fastonosql
