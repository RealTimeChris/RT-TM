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

#include <rt_tm/common/model_graph.hpp>
#include <rt_tm/common/debugging_io.hpp>
#include <variant>
#include <map>
#include <bit>

namespace rt_tm {

	enum class gguf_metadata_value_type : uint32_t {
		GGUF_METADATA_VALUE_TYPE_UINT8	 = 0,
		GGUF_METADATA_VALUE_TYPE_INT8	 = 1,
		GGUF_METADATA_VALUE_TYPE_UINT16	 = 2,
		GGUF_METADATA_VALUE_TYPE_INT16	 = 3,
		GGUF_METADATA_VALUE_TYPE_UINT32	 = 4,
		GGUF_METADATA_VALUE_TYPE_INT32	 = 5,
		GGUF_METADATA_VALUE_TYPE_FLOAT32 = 6,
		GGUF_METADATA_VALUE_TYPE_BOOL	 = 7,
		GGUF_METADATA_VALUE_TYPE_STRING	 = 8,
		GGUF_METADATA_VALUE_TYPE_ARRAY	 = 9,
		GGUF_METADATA_VALUE_TYPE_UINT64	 = 10,
		GGUF_METADATA_VALUE_TYPE_INT64	 = 11,
		GGUF_METADATA_VALUE_TYPE_FLOAT64 = 12,
		GGUF_METADATA_VALUE_TYPE_UNSET	 = 13,
	};

	struct string_iterator {
		const char* first_index{};
		size_t current_index{};
		size_t length{};
	};

	template<typename value_type> struct value_reader {
		RT_TM_FORCE_INLINE static gguf_metadata_value_type read_value(string_iterator& input) {
			gguf_metadata_value_type value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			if (static_cast<size_t>(value) >= 13) {
				throw std::runtime_error{ "Sorry, but that type is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<uint8_t> {
		RT_TM_FORCE_INLINE static uint8_t read_value(string_iterator& input) {
			uint8_t value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<uint16_t> {
		RT_TM_FORCE_INLINE static uint16_t read_value(string_iterator& input) {
			uint16_t value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<uint32_t> {
		RT_TM_FORCE_INLINE static uint32_t read_value(string_iterator& input) {
			uint32_t value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<uint64_t> {
		RT_TM_FORCE_INLINE static uint64_t read_value(string_iterator& input) {
			uint64_t value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<int8_t> {
		RT_TM_FORCE_INLINE static int8_t read_value(string_iterator& input) {
			int8_t value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<int16_t> {
		RT_TM_FORCE_INLINE static int16_t read_value(string_iterator& input) {
			int16_t value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<int32_t> {
		RT_TM_FORCE_INLINE static int32_t read_value(string_iterator& input) {
			int32_t value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<int64_t> {
		RT_TM_FORCE_INLINE static int64_t read_value(string_iterator& input) {
			int64_t value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<bool> {
		RT_TM_FORCE_INLINE static bool read_value(string_iterator& input) {
			bool value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<float> {
		RT_TM_FORCE_INLINE static float read_value(string_iterator& input) {
			float value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<double> {
		RT_TM_FORCE_INLINE static double read_value(string_iterator& input) {
			double value{};
			if (input.current_index + sizeof(value) < input.length) {
				std::memcpy(&value, input.first_index + input.current_index, sizeof(value));
				input.current_index += sizeof(value);
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	using gguf_string_t = std::string;

	struct gguf_array_t;

	using gguf_metadata_value_variant = std::variant<float, uint64_t, int64_t, double, bool, gguf_string_t, gguf_array_t*>;

	template<typename value_type> struct non_unique_ptr {};

	struct gguf_metadata_value_t {
		gguf_metadata_value_t() noexcept = default;
		gguf_metadata_value_t& operator=(const gguf_metadata_value_t& other) noexcept;
		gguf_metadata_value_t(const gguf_metadata_value_t&other) noexcept {
			*this = other;
		};
		gguf_metadata_value_t(const gguf_metadata_value_variant& other) noexcept;
		gguf_metadata_value_variant value{};
		~gguf_metadata_value_t();
	};

	struct gguf_array_t {
		std::vector<gguf_metadata_value_t> array{};
		gguf_metadata_value_type type{};
	};

	gguf_metadata_value_t::~gguf_metadata_value_t() {
		switch (value.index()) {
			case 6: {
				if (std::get<gguf_array_t*>(value)) {
					delete std::get<gguf_array_t*>(value);
				}
			}
		}
	}

	gguf_metadata_value_t& gguf_metadata_value_t::operator=(const gguf_metadata_value_t& other) noexcept {
		switch (other.value.index()) {
			case 0: {
				value.emplace<float>(std::get<float>(other.value));
				break;
			}
			case 1: {
				value.emplace<uint64_t>(std::get<uint64_t>(other.value));
				break;
			}
			case 2: {
				value.emplace<int64_t>(std::get<int64_t>(other.value));
				break;
			}
			case 3: {
				value.emplace<double>(std::get<double>(other.value));
				break;
			}
			case 4: {
				value.emplace<bool>(std::get<bool>(other.value));
				break;
			}
			case 5: {
				value.emplace<gguf_string_t>(std::get<gguf_string_t>(other.value));
				break;
			}
			case 6: {
				value.emplace<gguf_array_t*>(new gguf_array_t{ *std::get<gguf_array_t*>(other.value) });
				break;
			}
		}
		return *this;
	};

	gguf_metadata_value_t::gguf_metadata_value_t(const gguf_metadata_value_variant& other) noexcept {
		switch (other.index()) {
			case 0: {
				value.emplace<float>(std::get<float>(other));
				break;
			}
			case 1: {
				value.emplace<uint64_t>(std::get<uint64_t>(other));
				break;
			}
			case 2: {
				value.emplace<int64_t>(std::get<int64_t>(other));
				break;
			}
			case 3: {
				value.emplace<double>(std::get<double>(other));
				break;
			}
			case 4: {
				value.emplace<bool>(std::get<bool>(other));
				break;
			}
			case 5: {
				value.emplace<gguf_string_t>(std::get<gguf_string_t>(other));
				break;
			}
			case 6: {
				value.emplace<gguf_array_t*>(new gguf_array_t{ *std::get<gguf_array_t*>(other) });
				break;
			}
		}
	};

	template<> struct value_reader<gguf_string_t> {
		RT_TM_FORCE_INLINE static gguf_string_t read_value(string_iterator& input) {
			uint64_t length{ value_reader<uint64_t>::read_value(input) };
			gguf_string_t value{};
			value.resize(length);
			if (input.current_index + length < input.length) {
				std::memcpy(value.data(), input.first_index + input.current_index, length);
				input.current_index += length;
			} else {
				throw std::runtime_error{ "Sorry, but that index is out of range!" };
			}
			return value;
		}
	};

	template<> struct value_reader<gguf_array_t> {
		RT_TM_FORCE_INLINE static gguf_array_t read_value(string_iterator& input);
	};

	template<> struct value_reader<gguf_metadata_value_variant> {
		RT_TM_INLINE static gguf_metadata_value_variant read_value(string_iterator& input, gguf_metadata_value_type type) {
			gguf_metadata_value_variant value{};
			switch (type) {
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_INT8: {
					value.emplace<int64_t>(value_reader<int8_t>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_INT16: {
					value.emplace<int64_t>(value_reader<int16_t>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_INT32: {
					value.emplace<int64_t>(value_reader<int32_t>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_INT64: {
					value.emplace<int64_t>(value_reader<int64_t>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_UINT8: {
					value.emplace<uint64_t>(value_reader<uint8_t>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_UINT16: {
					value.emplace<uint64_t>(value_reader<uint16_t>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_UINT32: {
					value.emplace<uint64_t>(value_reader<uint32_t>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_UINT64: {
					value.emplace<uint64_t>(value_reader<uint64_t>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_BOOL: {
					value.emplace<bool>(value_reader<bool>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_FLOAT32: {
					value.emplace<float>(value_reader<float>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_FLOAT64: {
					value.emplace<double>(value_reader<double>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_STRING: {
					value.emplace<gguf_string_t>(value_reader<gguf_string_t>::read_value(input));
					break;
				}
				case gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_ARRAY: {
					value.emplace<gguf_array_t*>(new gguf_array_t{ value_reader<gguf_array_t>::read_value(input) });
					break;
				}
			}
			return value;
		}
	};

	gguf_array_t value_reader<gguf_array_t>::read_value(string_iterator& input) {
		gguf_metadata_value_type type{ value_reader<gguf_metadata_value_type>::read_value(input) };
		uint64_t length{ value_reader<uint64_t>::read_value(input) };
		gguf_array_t value{};
		value.type = type;
		for (size_t x = 0; x < length; ++x) {
			value.array.emplace_back(value_reader<gguf_metadata_value_variant>::read_value(input, type));
		}
		return value;
	}

	struct gguf_metadata_kv_t;	

	struct gguf_metadata_kv_t {

		gguf_metadata_value_type value_type{};

		gguf_metadata_value_t value{};

		RT_TM_FORCE_INLINE operator bool() const {
			return std::get<bool>(value.value);
		}

		RT_TM_FORCE_INLINE operator int64_t() const {
			return std::get<int64_t>(value.value);
		}

		RT_TM_FORCE_INLINE operator uint64_t() const {
			return std::get<uint64_t>(value.value);
		}

		RT_TM_FORCE_INLINE operator gguf_string_t() const {
			return std::get<gguf_string_t>(value.value);
		}

		RT_TM_FORCE_INLINE operator gguf_array_t() const {
			return *std::get<gguf_array_t*>(value.value);
		}

		RT_TM_FORCE_INLINE operator float() const {
			return std::get<float>(value.value);
		}

		RT_TM_FORCE_INLINE operator double() const {
			return std::get<double>(value.value);
		}
	};

	template<> struct value_reader<gguf_metadata_kv_t> {
		RT_TM_FORCE_INLINE static gguf_metadata_kv_t read_value(string_iterator& input) {
			gguf_metadata_kv_t value{};
			value.value_type = value_reader<gguf_metadata_value_type>::read_value(input);
			value.value.value	   = value_reader<gguf_metadata_value_variant>::read_value(input, value.value_type);
			return value;
		}
	};

	struct gguf_header_t {
		// Magic number to announce that this is a GGUF file.
		// Must be `GGUF` at the byte level: `0x47` `0x47` `0x55` `0x46`.
		// Your executor might do little-endian byte order, so it might be
		// check for 0x46554747 and letting the endianness cancel out.
		// Consider being *very* explicit about the byte order here.
		uint32_t magic{};
		uint32_t version{};
		uint64_t tensor_count{};
		uint64_t metadata_kv_count{};
		std::map<std::string, gguf_metadata_kv_t> metadata_kv{};
	};

	RT_TM_FORCE_INLINE void read_u64(const std::string& key, uint64_t& out, const std::map<std::string, gguf_metadata_kv_t>& metadata_kv) {
		auto it = metadata_kv.find(key);
		if (it == metadata_kv.end())
			return;
		const auto& v = it->second.value.value;
		if (std::holds_alternative<uint64_t>(v)) {
			out = std::get<uint64_t>(v);
		} else if (std::holds_alternative<int64_t>(v)) {
			out = static_cast<uint64_t>(std::get<int64_t>(v));
		}
	};

	RT_TM_FORCE_INLINE void read_f32(const std::string& key, float& out, const std::map<std::string, gguf_metadata_kv_t>& metadata_kv) {
		auto it = metadata_kv.find(key);
		if (it != metadata_kv.end() && std::holds_alternative<float>(it->second.value.value)) {
			out = std::get<float>(it->second.value.value);
		}
	};

	RT_TM_FORCE_INLINE void read_str(const std::string& key, std::string& out, const std::map<std::string, gguf_metadata_kv_t>& metadata_kv) {
		auto it = metadata_kv.find(key);
		if (it != metadata_kv.end() && std::holds_alternative<gguf_string_t>(it->second.value.value)) {
			out = std::get<gguf_string_t>(it->second.value.value);
		}
	};

	RT_TM_FORCE_INLINE void read_str_array(const std::string& key, std::vector<std::string>& out, const std::map<std::string, gguf_metadata_kv_t>& metadata_kv) {
		auto it = metadata_kv.find(key);
		if (it == metadata_kv.end())
			return;
		const auto& v = it->second.value.value;
		if (std::holds_alternative<gguf_array_t*>(v)) {
			gguf_array_t& new_array{ *std::get<gguf_array_t*>(v) };
			for (auto& value: new_array.array) {
				out.emplace_back(std::get<gguf_string_t>(value.value));
			}
		}
	};

	RT_TM_FORCE_INLINE void read_int_array(const std::string& key, std::vector<int64_t>& out, const std::map<std::string, gguf_metadata_kv_t>& metadata_kv) {
		auto it = metadata_kv.find(key);
		if (it == metadata_kv.end())
			return;
		const auto& v = it->second.value.value;
		if (std::holds_alternative<gguf_array_t*>(v)) {
			gguf_array_t& new_array{ *std::get<gguf_array_t*>(v) };
			for (auto& value: new_array.array) {
				out.emplace_back(std::get<int64_t>(value.value));
			}
		}
	};

	template<> struct value_reader<hyper_parameters> {
		RT_TM_FORCE_INLINE static hyper_parameters read_value(const std::map<std::string, gguf_metadata_kv_t>& metadata_kv) {
			hyper_parameters value{};
			std::string architecture{};

			if (metadata_kv.contains("general.architecture")) {
				architecture = metadata_kv.at("general.architecture").operator gguf_string_t();
			}

			read_u64(architecture + ".block_count", value.block_count, metadata_kv);
			read_u64(architecture + ".quantization_version", value.quantization_version, metadata_kv);
			read_u64(architecture + ".rope_dimension_count", value.rope_dimension_count, metadata_kv);
			read_u64(architecture + ".feed_forward_length", value.feed_forward_length, metadata_kv);
			read_u64(architecture + ".embedding_length", value.embedding_length, metadata_kv);
			read_u64(architecture + ".context_length", value.context_length, metadata_kv);
			read_u64(architecture + ".head_count_kv", value.head_count_kv, metadata_kv);
			read_u64(architecture + ".attention.head_count", value.head_count, metadata_kv);
			read_u64(architecture + ".vocab_size", value.vocab_size, metadata_kv);
			read_u64("general.file_type", value.file_type, metadata_kv);
			read_f32(architecture + ".attention.layer_norm_rms_epsilon", value.rms_norm_epsilon, metadata_kv);
			read_f32(architecture + ".rope.freq_base", value.rope_freq_base, metadata_kv);
			read_u64("quantize.imatrix.entries_count", value.imatrix_entries_count, metadata_kv);
			read_u64("quantize.imatrix.chunks_count", value.imatrix_chunks_count, metadata_kv);
			read_str("quantize.imatrix.file", value.imatrix_file, metadata_kv);

			return value;
		}
	};

	template<> struct value_reader<tokenizer_parameters> {
		RT_TM_FORCE_INLINE static tokenizer_parameters read_value(const std::map<std::string, gguf_metadata_kv_t>& metadata_kv) {
			tokenizer_parameters value{};

			read_u64("tokenizer.ggml.bos_token_id", value.bos_token_id, metadata_kv);
			read_u64("tokenizer.ggml.eos_token_id", value.eos_token_id, metadata_kv);
			read_str("tokenizer.chat_template", value.chat_template, metadata_kv);
			read_str_array("tokenizer.ggml.merges", value.merges, metadata_kv);
			read_str("tokenizer.ggml.pre", value.pre, metadata_kv);
			read_str_array("tokenizer.ggml.tokens", value.tokens, metadata_kv);
			read_int_array("tokenizer.ggml.token_type", value.token_types, metadata_kv);
			return value;
		}
	};

	template<> struct value_reader<gguf_header_t> {
		RT_TM_FORCE_INLINE static gguf_header_t read_value(string_iterator& input) {
			gguf_header_t value{};
			value.magic = value_reader<uint32_t>::read_value(input);
			if (value.magic != 0x46554747) {
				throw std::runtime_error{ "Sorry, but that magic value was incorrect!" };
			}
			value.version = value_reader<uint32_t>::read_value(input);
			value.tensor_count = value_reader<uint64_t>::read_value(input);
			value.metadata_kv_count = value_reader<uint64_t>::read_value(input);
			for (size_t x = 0; x < value.metadata_kv_count; ++x) {
				std::string new_string = value_reader<gguf_string_t>::read_value(input);
				std::cout << new_string << ": ";
				value.metadata_kv[new_string] = value_reader<gguf_metadata_kv_t>::read_value(input);
				if (value.metadata_kv[new_string].value_type == gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_STRING) {
					std::cout<< value.metadata_kv[new_string].operator std::string() << std::endl;
				} else if (value.metadata_kv[new_string].value_type == gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_INT32) {
					std::cout << value.metadata_kv[new_string].operator int64_t() << std::endl;
				} else if (value.metadata_kv[new_string].value_type == gguf_metadata_value_type::GGUF_METADATA_VALUE_TYPE_UINT32) {
					
					std::cout << value.metadata_kv[new_string].operator uint64_t() << std::endl;
				} else {
					std::cout << std::endl;
				}
			}
			std::cout<< std::hex << +value.magic << std::endl;
			std::cout<< std::dec << +value.version << std::endl;
			std::cout<< std::dec << +value.tensor_count << std::endl;
			std::cout<< std::dec << +value.metadata_kv_count << std::endl;
			return value;
		}
	};

	uint64_t align_offset(uint64_t offset, size_t ALIGNMENT) {
		return offset + (ALIGNMENT - (offset % ALIGNMENT)) % ALIGNMENT;
	}

	struct gguf_tensor_info_t {
		gguf_string_t name{};
		uint32_t n_dimensions{};
		std::vector<uint64_t> dimensions{};
		data_type type{};
		uint64_t offset{};
	};

	template<> struct value_reader<gguf_tensor_info_t> {
		RT_TM_FORCE_INLINE static gguf_tensor_info_t read_value(string_iterator& input) {
			gguf_tensor_info_t value{};
			value.name = value_reader<gguf_string_t>::read_value(input);
			value.n_dimensions = value_reader<uint32_t>::read_value(input);
			for (size_t x = 0; x < value.n_dimensions; ++x) {
				value.dimensions.emplace_back(value_reader<uint64_t>::read_value(input));
			}
			value.type = static_cast<data_type>(value_reader<uint32_t>::read_value(input));
			value.offset = value_reader<uint64_t>::read_value(input);
			std::cout<< std::hex << value.name << std::endl;
			return value;
		}
	};

	struct gguf_file_t {
		gguf_header_t header{};
		std::vector<gguf_tensor_info_t> tensor_infos{};
		std::vector<uint8_t> _padding{};
		std::vector<uint8_t> tensor_data{};
	};

	enum class model_format { gguf = 1 };

	template<global_config config, model_format type> struct model_parser;

	template<global_config config> struct model_parser<config, model_format::gguf> {
		static_assert((std::endian::native == std::endian::little), "Sorry, but big-endian is not yet supported by the library");
		RT_TM_FORCE_INLINE static model_graph parse_model(std::string_view path) {
			std::string data_val{};
			model_graph return_value{};
			data_val = file_loader<config.exceptions>{ path };
			gguf_file_t gguf_file{};
			string_iterator ptr{};
			ptr.first_index	 = data_val.data();
			ptr.length		 = data_val.size();
			gguf_file.header = value_reader<gguf_header_t>::read_value(ptr);
			for (size_t x = 0; x < gguf_file.header.tensor_count; ++x) {
				gguf_file.tensor_infos.emplace_back(value_reader<gguf_tensor_info_t>::read_value(ptr));
			}
			return_value.hparams = value_reader<hyper_parameters>::read_value(gguf_file.header.metadata_kv);
			return_value.tokenizer_params = value_reader<tokenizer_parameters>::read_value(gguf_file.header.metadata_kv);
			return return_value;
		}
	};

}
