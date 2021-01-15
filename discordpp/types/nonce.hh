//
// Created by Aidan on 1/10/2021.
//

#pragma once

#include <nlohmann/json.hpp>
#include <variant>

namespace discordpp {
using json = nlohmann::json;

using Nonce = std::variant<int, std::string>;
} // namespace discordpp

namespace nlohmann {
template <> struct adl_serializer<discordpp::Nonce> {
    static void to_json(json &j, const discordpp::Nonce &n) {
        std::visit(
            [&](auto &&value) { j = std::forward<decltype(value)>(value); }, n);
    }
    static void from_json(const json &j, discordpp::Nonce &n) {
        if (j.is_number_integer()) {
            n = j.get<int>();
        } else if (j.is_string()) {
            n = j.get<std::string>();
        } else {
            assert(false && "\"nonce\" wasn't a sting or int");
        }
    }
};
} // namespace nlohmann