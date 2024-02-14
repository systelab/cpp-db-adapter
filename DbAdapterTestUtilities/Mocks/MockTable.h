#pragma once

#include "DbAdapterInterface/ITable.h"
#include "DbAdapterInterface/IBinaryValue.h"

namespace systelab::db::test_utility {

	class MockTable: public ITable
	{
	public:
		MockTable();
		~MockTable() override;

		MOCK_METHOD(std::string, getName, (), (const, override));
		MOCK_METHOD(const IPrimaryKey&, getPrimaryKey, (), (const, override));

		MOCK_METHOD(unsigned int, getFieldsCount, (), (const, override));
		MOCK_METHOD(const IField&, getField, (unsigned int), (const, override));
		MOCK_METHOD(const IField&, getField, (const std::string&), (const, override));

		MOCK_METHOD(std::unique_ptr<IFieldValue>, createFieldValue, (const IField&), (const, override));
		MOCK_METHOD(std::unique_ptr<IFieldValue>, createFieldValue, (const IField&, bool), (const, override));
		MOCK_METHOD(std::unique_ptr<IFieldValue>, createFieldValue, (const IField&, int), (const, override));
		MOCK_METHOD(std::unique_ptr<IFieldValue>, createFieldValue, (const IField&, double), (const, override));
		MOCK_METHOD(std::unique_ptr<IFieldValue>, createFieldValue, (const IField&, const std::string&), (const, override));
		MOCK_METHOD(std::unique_ptr<IFieldValue>, createFieldValue, (const IField&, const std::chrono::system_clock::time_point&), (const, override));
		MOCK_METHOD(std::unique_ptr<IFieldValue>, createFieldValue, (const IField&, std::unique_ptr<IBinaryValue>), (const, override));
		MOCK_METHOD(std::unique_ptr<IPrimaryKeyValue>, createPrimaryKeyValue, (), (const, override));
		MOCK_METHOD(std::unique_ptr<ITableRecordSet>, getAllRecords, (), (const override));
		MOCK_METHOD(std::unique_ptr<ITableRecord>, getRecordByPrimaryKey, (const IPrimaryKeyValue&), (const, override));
		MOCK_METHOD(std::unique_ptr<ITableRecordSet>, filterRecordsByField, (const IFieldValue&, const IField*), (const, override));
		MOCK_METHOD(std::unique_ptr<ITableRecordSet>, filterRecordsByFieldsProxy, (const std::vector<IFieldValue*>&, const IField*), (const));
		std::unique_ptr<db::ITableRecordSet> filterRecordsByFields(const std::vector<db::IFieldValue*>& conditionValues, const db::IField* orderByField = nullptr) const override
		{
			return std::unique_ptr<db::ITableRecordSet>(filterRecordsByFieldsProxy(conditionValues, orderByField));
		}

		MOCK_METHOD(std::unique_ptr<db::ITableRecordSet>, filterRecordsByCondition, (const std::string&), (const, override));
		MOCK_METHOD(int, getMaxFieldValueInt, (const IField&), (const, override));
		
		MOCK_METHOD(std::unique_ptr<ITableRecord>, createRecord, (), (const, override));
		MOCK_METHOD(std::unique_ptr<ITableRecord>, copyRecord, (const ITableRecord&), (const, override));

		MOCK_METHOD(RowsAffected, insertRecord, (ITableRecord&), (override));
		MOCK_METHOD(RowsAffected, updateRecord, (const ITableRecord&), (override));
		MOCK_METHOD(RowsAffected, updateRecord, (const std::vector<IFieldValue*>&, const IPrimaryKeyValue&), (override));
		MOCK_METHOD(RowsAffected, deleteRecord, (const ITableRecord&), (override));
		MOCK_METHOD(RowsAffected, deleteRecord, (const IPrimaryKeyValue&), (override));

		MOCK_METHOD(RowsAffected, updateRecordsByCondition, (const std::vector<IFieldValue*>&, const std::vector<IFieldValue*>&), (override));
		MOCK_METHOD(RowsAffected, deleteRecordsByCondition, (const std::vector<IFieldValue*>&), (override));
		MOCK_METHOD(RowsAffected, deleteRecordsByCondition, (const std::string& condition), (override));

		MOCK_METHOD(RowsAffected, deleteAllRecords, (), (override));
	};
}

