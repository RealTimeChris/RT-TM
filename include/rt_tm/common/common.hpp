/*
MIT License

Copyright (c) 2025 RealTimeChris (Chris M)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "RT-TM Library"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

This file was independently created by RealTimeChris (Chris M), without reuse
or derivation from any codebase owned by other entities, including any contract work.

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT
OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <cstdint>

namespace rt_tm {

	enum class data_type : uint32_t {
		float_32 = 0,
		float_16 = 1,
		q4_0	 = 2,
		q4_1	 = 3,
		q5_0	 = 6,
		q5_1	 = 7,
		q8_0	 = 8,
		q8_1	 = 9,
		q2_k	 = 10,
		q3_k	 = 11,
		q4_k	 = 12,
		q5_k	 = 13,
		q6_k	 = 14,
		q8_k	 = 15,
		iq2_xxs	 = 16,
		iq2_xs	 = 17,
		iq3_xxs	 = 18,
		iq1_s	 = 19,
		iq4_nl	 = 20,
		iq3_s	 = 21,
		iq2_s	 = 22,
		iq4_xs	 = 23,
		int_8	 = 24,
		int_16	 = 25,
		int_32	 = 26,
		int_64	 = 27,
		float_64 = 28,
		iqq_m	 = 29,
		count,
	};

    enum class device_type {
		cpu = 0,
		gpu = 1,
	};

    struct global_config {
		bool exceptions{};
    };

	struct cli_params {
		std::string model_file{};
		size_t thread_count{};
	};

}
