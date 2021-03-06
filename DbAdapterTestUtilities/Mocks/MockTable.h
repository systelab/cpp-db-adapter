#pragma once

#include "DbAdapterInterface/ITable.h"


namespace systelab { namespace db { namespace test_utility {

	class MockTable: public ITable
	{
	public:
		MockTable();
		virtual ~MockTable();

		MOCK_CONST_METHOD0(getName, std::string ());
		MOCK_CONST_METHOD0(getPrimaryKey, const db::IPrimaryKey&());

		MOCK_CONST_METHOD0(getFieldsCount, unsigned int());
		MOCK_CONST_METHOD1(getField, const db::IField& (unsigned int));
		MOCK_CONST_METHOD1(getField, const db::IField& (const std::string&));

		MOCK_CONST_METHOD1(createFieldValueProxy, db::IFieldValue* (const db::IField&));
		std::unique_ptr<db::IFieldValue> createFieldValue(const db::IField& field) const
		{
			return std::unique_ptr<db::IFieldValue>(createFieldValueProxy(field));
		}

		MOCK_CONST_METHOD2(createFieldValueProxy, db::IFieldValue* (const db::IField&, bool));
		std::unique_ptr<db::IFieldValue> createFieldValue(const db::IField& field, bool value) const
		{
			return std::unique_ptr<db::IFieldValue>(createFieldValueProxy(field, value));
		}

		MOCK_CONST_METHOD2(createFieldValueProxy, db::IFieldValue* (const db::IField&, int));
		std::unique_ptr<db::IFieldValue> createFieldValue(const db::IField& field, int value) const
		{
			return std::unique_ptr<db::IFieldValue>(createFieldValueProxy(field, value));
		}

		MOCK_CONST_METHOD2(createFieldValueProxy, db::IFieldValue* (const db::IField&, double));
		std::unique_ptr<db::IFieldValue> createFieldValue(const db::IField& field, double value) const
		{
			return std::unique_ptr<db::IFieldValue>(createFieldValueProxy(field, value));
		}

		MOCK_CONST_METHOD2(createFieldValueProxy, db::IFieldValue* (const db::IField&, const std::string&));
		std::unique_ptr<db::IFieldValue> createFieldValue(const db::IField& field, const std::string& value) const
		{
			return std::unique_ptr<db::IFieldValue>(createFieldValueProxy(field, value));
		}

		MOCK_CONST_METHOD2(createFieldValueProxy, db::IFieldValue* (const db::IField&, const boost::posix_time::ptime&));
		std::unique_ptr<db::IFieldValue> createFieldValue(const db::IField& field, const boost::posix_time::ptime& value) const
		{
			return std::unique_ptr<db::IFieldValue>(createFieldValueProxy(field, value));
		}

		MOCK_CONST_METHOD2(createFieldValueProxy, db::IFieldValue* (const db::IField&, db::IBinaryValue*));
		std::unique_ptr<db::IFieldValue> createFieldValue(const db::IField& field, std::unique_ptr<db::IBinaryValue> value) const
		{
			return std::unique_ptr<db::IFieldValue>(createFieldValueProxy(field, value.release()));
		}

		MOCK_CONST_METHOD0(createPrimaryKeyValueProxy, db::IPrimaryKeyValue*());
		std::unique_ptr<db::IPrimaryKeyValue> createPrimaryKeyValue() const
		{
			return std::unique_ptr<db::IPrimaryKeyValue>(createPrimaryKeyValueProxy());
		}

		MOCK_CONST_METHOD0(getAllRecordsProxy, db::ITableRecordSet*());
		std::unique_ptr<db::ITableRecordSet> getAllRecords() const
		{
			return std::unique_ptr<db::ITableRecordSet>(getAllRecordsProxy());
		}

		MOCK_CONST_METHOD1(getRecordByPrimaryKeyProxy, db::ITableRecord* (const db::IPrimaryKeyValue&));
		std::unique_ptr<db::ITableRecord> getRecordByPrimaryKey(const db::IPrimaryKeyValue& primaryKeyValue) const
		{
			return std::unique_ptr<db::ITableRecord>(getRecordByPrimaryKeyProxy(primaryKeyValue));
		}

		MOCK_CONST_METHOD2(filterRecordsByFieldProxy, db::ITableRecordSet* (const db::IFieldValue&, const db::IField*));
		std::unique_ptr<db::ITableRecordSet> filterRecordsByField(const db::IFieldValue& conditionValue, const db::IField* orderByField = NULL) const
		{
			return std::unique_ptr<db::ITableRecordSet>(filterRecordsByFieldProxy(conditionValue, orderByField));
		}

		MOCK_CONST_METHOD1(getMaxFieldValueInt, int (const db::IField&));

		MOCK_CONST_METHOD2(filterRecordsByFieldsProxy, db::ITableRecordSet* (const std::vector<db::IFieldValue*>&, const db::IField*));
		std::unique_ptr<db::ITableRecordSet> filterRecordsByFields(const std::vector<db::IFieldValue*>& conditionValues, const db::IField* orderByField = NULL) const
		{
			return std::unique_ptr<db::ITableRecordSet>(filterRecordsByFieldsProxy(conditionValues, orderByField));
		}

		MOCK_CONST_METHOD1(filterRecordsByConditionProxy, db::ITableRecordSet* (const std::string& condition));
		std::unique_ptr<db::ITableRecordSet> filterRecordsByCondition(const std::string& condition) const
		{
			return std::unique_ptr<db::ITableRecordSet>(filterRecordsByConditionProxy(condition));
		}

		MOCK_CONST_METHOD0(createRecordProxy, db::ITableRecord*());
		std::unique_ptr<db::ITableRecord> createRecord() const
		{
			return std::unique_ptr<db::ITableRecord>(createRecordProxy());
		}

		MOCK_CONST_METHOD1(copyRecordProxy, db::ITableRecord*(const db::ITableRecord&));
		std::unique_ptr<db::ITableRecord> copyRecord(const db::ITableRecord& record) const
		{
			return std::unique_ptr<db::ITableRecord>(copyRecordProxy(record));
		}

		MOCK_METHOD1(insertRecord, db::RowsAffected(db::ITableRecord&));
		MOCK_METHOD1(updateRecord, db::RowsAffected(const db::ITableRecord&));
		MOCK_METHOD2(updateRecord, db::RowsAffected(const std::vector<db::IFieldValue*>&, const db::IPrimaryKeyValue&));
		MOCK_METHOD1(deleteRecord, db::RowsAffected(const db::ITableRecord&));
		MOCK_METHOD1(deleteRecord, db::RowsAffected(const db::IPrimaryKeyValue&));

		MOCK_METHOD2(updateRecordsByCondition, db::RowsAffected(const std::vector<db::IFieldValue*>&, const std::vector<db::IFieldValue*>&));
		MOCK_METHOD1(deleteRecordsByCondition, db::RowsAffected(const std::vector<db::IFieldValue*>&));
		MOCK_METHOD1(deleteRecordsByCondition, db::RowsAffected(const std::string& condition));

		MOCK_METHOD0(deleteAllRecords, db::RowsAffected());
	};

}}}

