#pragma once

#ifdef JSON4CPP_EXPORTS
#define JSON_API __declspec(dllexport)
#else
#define JSON_API __declspec(dllimport)
#endif

#include "Value.h"
#include "JsonLinter.h"

#include <vector>
#include <deque>
#include <unordered_map>
#include <utility>
#include <sstream>
#include <iostream>
#include <initializer_list>
#include <string>

namespace Json4CPP
{
  class JSON_API JsonArray;
  class JSON_API Json;
  class JSON_API JsonIterator;
  class JSON_API JsonConstIterator;

  class JSON_API JsonObject
  {
  private:
    friend class JsonArray;
    friend class Json;
    friend class JsonIterator;
    friend class JsonConstIterator;
#pragma warning(suppress: 4251)
    std::vector<std::pair<KEY, Json>> _pairs;
#pragma warning(suppress: 4251)
    std::unordered_map<KEY, int64_t> _indexes;

    static JsonObject                   Read (                          std::deque<Detail::TOKEN>  & tokens);
    static JsonObject                   Read (                          std::deque<Detail::TOKEN> && tokens);
    static std::deque<Detail::TOKEN>  & Write(JsonObject const& object, std::deque<Detail::TOKEN>  & tokens);
    static std::deque<Detail::TOKEN> && Write(JsonObject const& object, std::deque<Detail::TOKEN> && tokens);
  public:
    JsonObject() = default;
    JsonObject(Json const& json);
    JsonObject(Json     && json);
    JsonObject(Detail::JsonBuilder const& builder);
    JsonObject(Detail::JsonBuilder     && builder);
    JsonObject(std::initializer_list<Detail::JsonBuilder> builders);

    std::wstring Dump(uint8_t indentSize = 0, wchar_t indentChar = L' ') const;

    int64_t Size() const;
    void Clear();
    bool Insert(std::pair<KEY, Json> const& pair);
    bool Insert(std::pair<KEY, Json>     && pair);
    void Erase(KEY const& key);
    std::vector<KEY> Keys() const;
    std::vector<std::reference_wrapper<const KEY>> KeysView() const;
    Json      & operator[](KEY const& key);
    Json      & At(KEY const& key);
    Json const& At(KEY const& key) const;

    std::vector<std::pair<KEY, Json>>::      iterator begin();
    std::vector<std::pair<KEY, Json>>::      iterator end  ();
    std::vector<std::pair<KEY, Json>>::const_iterator begin() const;
    std::vector<std::pair<KEY, Json>>::const_iterator end  () const;

    JSON_API friend std::wostream& operator<<(std::wostream& os, JsonObject const& object);
    JSON_API friend std::wistream& operator>>(std::wistream& is, JsonObject      & object);

    JSON_API friend bool operator==(JsonObject const& left, JsonObject const& right);
    JSON_API friend bool operator!=(JsonObject const& left, JsonObject const& right);
  };
}