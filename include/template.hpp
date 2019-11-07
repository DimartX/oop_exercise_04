#pragma once

#inlcude <iostream>

// нужно разобраться, как это работает
template <typename ... Args> int ArgsCount(Args ... args) {
    return sizeof...(args);
}
