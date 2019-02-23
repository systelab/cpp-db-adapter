# Test utilities for C++ DB Adapter
This folder contains Google test utilities for any library that implements the [C++ DB adapter](https://github.com/systelab/cpp-db-adapter) interface.

The following types of utilities are available:
* *Interface mocks*: defined using Google Mock framework, allows mocking the DB adapter
* *Interface stubs*: implementation of the adapter that extends the mocks by working as an in-memory database
* *Entity comparators*: allows comparing two DB items (entire DBs, tables, records or fields) and provides a detailed message with the first difference found
