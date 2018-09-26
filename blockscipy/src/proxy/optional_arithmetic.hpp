//
//  optional_arithmetic.hpp
//  blocksci_interface
//
//  Created by Harry Kalodner on 9/23/18.
//


#ifndef proxy_optional_arithmetic_hpp
#define proxy_optional_arithmetic_hpp

#include "proxy.hpp"

struct AddProxyOptionalArithMethods {
	template<typename T>
	void operator()(pybind11::class_<Proxy<T, ranges::optional<int64_t>>> &cl) {
		using P = Proxy<T, ranges::optional<int64_t>>;
		using P2 = Proxy<T, int64_t>;
		cl
		.def("__add__", [](P &p, int64_t val) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v = p(t);
				if (v) {
					return *v + val;
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__sub__", [](P &p, int64_t val) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v = p(t);
				if (v) {
					return *v - val;
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__mul__", [](P &p, int64_t val) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v = p(t);
				if (v) {
					return *v * val;
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__floordiv__", [](P &p, int64_t val) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v = p(t);
				if (v) {
					return *v / val;
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__mod__", [](P &p, int64_t val) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v = p(t);
				if (v) {
					return *v % val;
				} else {
					return ranges::nullopt;
				}
			}};
		})

		.def("__add__", [](P &p1, P2 &p2) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v1 = p1(t);
				if (v1) {
					return *v1 + p2(t);
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__sub__", [](P &p1, P2 &p2) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v1 = p1(t);
				if (v1) {
					return *v1 - p2(t);
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__mul__", [](P &p1, P2 &p2) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v1 = p1(t);
				if (v1) {
					return *v1 * p2(t);
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__floordiv__", [](P &p1, P2 &p2) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v1 = p1(t);
				if (v1) {
					return *v1 / p2(t);
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__mod__", [](P &p1, P2 &p2) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v1 = p1(t);
				if (v1) {
					return *v1 % p2(t);
				} else {
					return ranges::nullopt;
				}
			}};
		})

		.def("__add__", [](P &p1, P &p2) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v1 = p1(t);
				auto v2 = p2(t);
				if (v1 && v2) {
					return *v1 + *v2;
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__sub__", [](P &p1, P &p2) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v1 = p1(t);
				auto v2 = p2(t);
				if (v1 && v2) {
					return *v1 - *v2;
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__mul__", [](P &p1, P &p2) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v1 = p1(t);
				auto v2 = p2(t);
				if (v1 && v2) {
					return *v1 * *v2;
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__floordiv__", [](P &p1, P &p2) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v1 = p1(t);
				auto v2 = p2(t);
				if (v1 && v2) {
					return *v1 / *v2;
				} else {
					return ranges::nullopt;
				}
			}};
		})
		.def("__mod__", [](P &p1, P &p2) -> P {
			return std::function<ranges::optional<int64_t>(T &)>{[=](T &t) -> ranges::optional<int64_t> {
				auto v1 = p1(t);
				auto v2 = p2(t);
				if (v1 && v2) {
					return *v1 % *v2;
				} else {
					return ranges::nullopt;
				}
			}};
		})
		;
	}
};

#endif /* proxy_optional_arithmetic_hpp */