/*************************************************************************

bq Cervantes e-book reader application
Copyright (C) 2011-2013  Mundoreader, S.L

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the source code.  If not, see <http://www.gnu.org/licenses/>.

*************************************************************************/

/**
 * \file json.h
 */

#ifndef JSON_H
#define JSON_H

#include <QVariant>
#include <QString>

/**
 * \enum JsonToken
 */
enum JsonToken
{
        JsonTokenNone = 0,
        JsonTokenCurlyOpen = 1,
        JsonTokenCurlyClose = 2,
        JsonTokenSquaredOpen = 3,
        JsonTokenSquaredClose = 4,
        JsonTokenColon = 5,
        JsonTokenComma = 6,
        JsonTokenString = 7,
        JsonTokenNumber = 8,
        JsonTokenTrue = 9,
        JsonTokenFalse = 10,
        JsonTokenNull = 11,
        JsonTokenStringWhite = 12
};

/**
 * \class Json
 * \brief A JSON data parser
 *
 * Json parses a JSON data into a QVariant hierarchy.
 */
class Json
{
        public:
                /**
                 * Parse a JSON string
                 *
                 * \param json The JSON data
                 */
                static QVariant parse(const QString &json);

                /**
                 * Parse a JSON string
                 *
                 * \param json The JSON data
                 * \param success The success of the parsing
                 */
                static QVariant parse(const QString &json, bool &success);

                /**
                * This method generates a textual JSON representation
                *
                * \param data The JSON data generated by the parser.
                * \param success The success of the serialization
                */
                static QByteArray serialize(const QVariant &data);

                /**
                * This method generates a textual JSON representation
                *
                * \param data The JSON data generated by the parser.
                * \param success The success of the serialization
                *
                * \return QByteArray Textual JSON representation
                */
                static QByteArray serialize(const QVariant &data, bool &success);

        private:
                /**
                 * Parses a value starting from index
                 *
                 * \param json The JSON data
                 * \param index The start index
                 * \param success The success of the parse process
                 *
                 * \return QVariant The parsed value
                 */
                static QVariant parseValue(const QString &json, int &index,
                                                                   bool &success);

                /**
                 * Parses an object starting from index
                 *
                 * \param json The JSON data
                 * \param index The start index
                 * \param success The success of the object parse
                 *
                 * \return QVariant The parsed object map
                 */
                static QVariant parseObject(const QString &json, int &index,
                                                                           bool &success);

                /**
                 * Parses an array starting from index
                 *
                 * \param json The JSON data
                 * \param index The starting index
                 * \param success The success of the array parse
                 *
                 * \return QVariant The parsed variant array
                 */
                static QVariant parseArray(const QString &json, int &index,
                                                                           bool &success);

                /**
                 * Parses a string starting from index
                 *
                 * \param json The JSON data
                 * \param index The starting index
                 * \param success The success of the string parse
                 *
                 * \return QVariant The parsed string
                 */
                static QVariant parseString(const QString &json, int &index,
                                                                        bool &success);

                /**
                 * Parses a number starting from index
                 *
                 * \param json The JSON data
                 * \param index The starting index
                 *
                 * \return QVariant The parsed number
                 */
                static QVariant parseNumber(const QString &json, int &index);

                /**
                 * Get the last index of a number starting from index
                 *
                 * \param json The JSON data
                 * \param index The starting index
                 *
                 * \return The last index of the number
                 */
                static int lastIndexOfNumber(const QString &json, int index);

                /**
                 * Skip unwanted whitespace symbols starting from index
                 *
                 * \param json The JSON data
                 * \param index The start index
                 */
                static void eatWhitespace(const QString &json, int &index);

                /**
                 * Check what token lies ahead
                 *
                 * \param json The JSON data
                 * \param index The starting index
                 *
                 * \return int The upcoming token
                 */
                static int lookAhead(const QString &json, int index);

                /**
                 * Get the next JSON token
                 *
                 * \param json The JSON data
                 * \param index The starting index
                 *
                 * \return int The next JSON token
                 */
                static int nextToken(const QString &json, int &index);

public:
                static QString sanitizeString(QString str);
};

#endif //JSON_H
