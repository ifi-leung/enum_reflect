# enum_reflect
The project provides macro definitions for converting enumeration values to strings.

Usage:

DECLARE_ENUM(OsType, Windows, Ubuntu = 50 , MacOS)

Define enumeration type OsType, which contains three enumeration members, where Windows equals 0, Ubuntu equals 50, and MacOS equals 51.

OsType::ToString(OsType::Windows);

Convert the enumerated value Windows to a string and return.