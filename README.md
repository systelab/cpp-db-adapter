[![Build Status](https://travis-ci.org/systelab/cpp-db-adapter.svg?branch=master)](https://travis-ci.org/systelab/cpp-db-adapter)
[![Build status](https://ci.appveyor.com/api/projects/status/56l40w9pu3i21bu8?svg=true)](https://ci.appveyor.com/project/systelab/cpp-db-adapter)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/f45f045c1a894879943e249547e10a3d)](https://www.codacy.com/app/systelab/cpp-db-adapter?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=systelab/cpp-db-adapter&amp;utm_campaign=Badge_Grade)

# C++ Database Adapter

This repository defines a library-agnostic API for C++ to work with a database

## Supported features

* Table queries
* Table record insert, update and delete
* SQL queries
* Transactions

## Available implementations

* [SQLite](https://github.com/systelab/cpp-sqlite-db-adapter)

## Usage

Build a database connection (`systelab::db::IDatabase`) using the particular instructions described on the selected implementation.

### Query table contents

```cpp
void queryTableContents(systelab::db::IDatabase& database, const std::string& tableName)
{
  systelab::db::ITable& table = database.getTable(tableName);
  std::unique_ptr<systelab::db::ITableRecordSet> recordset = table.getAllRecords();
  while (recordset->isCurrentRecordValid())
  {
    const systelab::db::ITableRecord& record = recordset->getCurrentRecord();

    // Extract data from current record
    int intValue = record.getFieldValue("intFieldName").getIntValue();
		std::string stringValue = record.getFieldValue("stringFieldName").getStringValue();
		boost::posix_time::ptime dateTimeValue = record.getFieldValue("dateTimeFieldName").getDateTimeValue();
    ...
    
		recordset->nextRecord();
	}
}
```

### Insert a new record

`TBD: Add a code snipped here`

### Update records by condition

`TBD: Add a code snipped here`

### Delete records by condition

`TBD: Add a code snipped here`

### Ad-hoc SQL queries

`TBD: Add a code snipped here`

### Transactions

`TBD: Add a code snipped here`
