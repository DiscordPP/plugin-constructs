//
// Created by Aidan on 1/14/2021.
//

#ifndef CONSTRUCTNAME
#error You need to define the CONSTRUCTNAME value.
#endif // CONSTRUCTNAME

#ifndef CONSTRUCTKEYS
#error You need to define the CONSTRUCTKEYS list.
#endif // CONSTRUCTKEYS

#define SNOWFLAKE                                                              \
    (j[key].is_null() ? nullptr : [&j, &key]() {                               \
        snowflake sf;                                                          \
        std::istringstream(j[key].get<std::string>()) >> sf;                   \
        return std::make_shared<snowflake>(sf);                                \
    }())
#define SNOWFLAKE_ARR                                                          \
    (j[key].is_null() ? nullptr : [&j, &key]() {                               \
        std::vector<snowflake> sfs;                                            \
        auto jk = j[key];                                                      \
        std::transform(jk.begin(), jk.end(), std::back_inserter(sfs),          \
                       [](const json &j) {                                     \
                           snowflake sf;                                       \
                           std::istringstream(j.get<std::string>()) >>         \
                               sf;                                             \
                           return sf;                                          \
                       });                                                     \
        return std::make_shared<const std::vector<snowflake>>(std::move(sfs)); \
    }())
#define TIME DEF(std::string)
#define DEF(TYPE)                                                              \
    (j[key].is_null() ? nullptr                                                \
                      : std::make_shared<const TYPE>(j[key].get<TYPE>()))
#define OPT(TYPE) (j.contains(key) ? std::make_optional(TYPE) : std::nullopt)
#define key(TYPE, KEY)                                                         \
    key = (const char *)#KEY;                                                  \
    construct.KEY = TYPE;

inline void from_json(const json &j, CONSTRUCTNAME &construct) {
    const char *key;
    CONSTRUCTKEYS
}

#undef SNOWFLAKE
#undef SNOWFLAKE_ARR
#undef TIME
#undef DEF
#undef OPT
#undef key
