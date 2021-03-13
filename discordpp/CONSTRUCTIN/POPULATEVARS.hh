//
// Created by Aidan on 1/14/2021.
//

#ifndef CONSTRUCTKEYS
#error You need to define the CONSTRUCTKEYS list.
#endif // CONSTRUCTKEYS

public:
#define SNOWFLAKE sptr<const snowflake>
#define SNOWFLAKE_ARR sptr<const std::vector<snowflake>>
#define TIME DEF(std::string)
#define DEF(TYPE) sptr<const TYPE>
#define OPT(TYPE) opt<TYPE>
#define key(TYPE, KEY) TYPE KEY{};
CONSTRUCTKEYS
#undef SNOWFLAKE
#undef SNOWFLAKE_ARR
#undef TIME
#undef DEF
#undef OPT
#undef key
