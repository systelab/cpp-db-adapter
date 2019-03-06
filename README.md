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

Build a database connection (`systelab::db::IDatabase`) using the particular instructions described on the selected implementation. This connection is the starting point for all the operations that interact with the database.

### Query table contents

```cpp
std::unique_ptr<systelab::db::IDatabase> database = connectToDatabase();
systelab::db::ITable& table = database->getTable("Table");

// Create a record set with all the records of the table and loop through it 
std::unique_ptr<systelab::db::ITableRecordSet> recordset = table.getAllRecords();
while (recordset->isCurrentRecordValid())
{
    const systelab::db::ITableRecord& record = recordset->getCurrentRecord();

    // Extract data from the current record
    int intValue = record.getFieldValue("intFieldName").getIntValue();
    std::string stringValue = record.getFieldValue("stringFieldName").getStringValue();
    boost::posix_time::ptime dateTimeValue = record.getFieldValue("dateTimeFieldName").getDateTimeValue();

    recordset->nextRecord();
}
```

### Insert a new record

```cpp
// Create an empty record for a table
systelab::db::ITable& table = database.getTable("Table");
std::unique_ptr<systelab::db::ITableRecord> record = table.createRecord();

// Fill record with data
record->getFieldValue("intFieldName").setIntValue(1234);
record->getFieldValue("stringFieldName").setStringValue("ABCDE");
record->getFieldValue("dateTimeFieldName").setDateTimeValue(boost::posix_time::ptime today({2020,10,23}));

// Perform the record insertion
table.insertRecord(*record);
```

### Update records by condition

`TBD: Add a code snipped here`

### Delete records by condition

`TBD: Add a code snipped here`

### Ad-hoc SQL queries

`TBD: Add a code snipped here`

### Transactions

`TBD: Add a code snipped here`
