template <char... C>
struct make_string {
    static constexpr char value[sizeof...(C) + 1] = {C..., '\0'};
};