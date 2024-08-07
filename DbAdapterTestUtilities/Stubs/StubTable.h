#pragma once

#include "DbAdapterTestUtilities/Mocks/MockTable.h"

namespace systelab::db::test_utility {

	class StubPrimaryKey;
	class StubTableRecord;

	class StubTable : public MockTable
	{
	public:
		StubTable(const std::string& name);
		virtual ~StubTable();

		std::string getName() const;
		const IPrimaryKey& getPrimaryKey() const;

		unsigned int getFieldsCount() const;
		const IField& getField(unsigned int index) const;
		const IField& getField(const std::string& fieldName) const;
		void addField(std::unique_ptr<IField> field);

		std::unique_ptr<IFieldValue> createFieldValue(const IField&) const;
		std::unique_ptr<IFieldValue> createFieldValue(const IField&, bool) const;
		std::unique_ptr<IFieldValue> createFieldValue(const IField&, int) const;
		std::unique_ptr<IFieldValue> createFieldValue(const IField&, double) const;
		std::unique_ptr<IFieldValue> createFieldValue(const IField&, const std::string&) const;
		std::unique_ptr<IFieldValue> createFieldValue(const IField&, const DateTimeType&) const;
		std::unique_ptr<IFieldValue> createFieldValue(const IField&, std::unique_ptr<IBinaryValue>) const;

		std::unique_ptr<IPrimaryKeyValue> createPrimaryKeyValue() const;

		std::unique_ptr<ITableRecordSet> getAllRecords() const;
		std::unique_ptr<ITableRecord> getRecordByPrimaryKey(const IPrimaryKeyValue&) const;
		int getMaxFieldValueInt(const IField&) const;

		std::unique_ptr<ITableRecord> createRecord() const;
		std::unique_ptr<ITableRecord> copyRecord(const ITableRecord&) const;

		RowsAffected insertRecordProxy(ITableRecord&);
		RowsAffected updateRecordProxy(const ITableRecord&);
		RowsAffected updateRecord(const std::vector<IFieldValue*>& newValues, const IPrimaryKeyValue&);
		RowsAffected deleteRecordProxy(const ITableRecord&);
		RowsAffected deleteRecord(const IPrimaryKeyValue&);

		RowsAffected updateRecordsByCondition(const std::vector<IFieldValue*>& newValues, const std::vector<IFieldValue*>& conditionValues);
		RowsAffected deleteRecordsByCondition(const std::vector<IFieldValue*>& conditionValues);
		RowsAffected deleteRecordsByCondition(const std::string& condition);

		RowsAffected deleteAllRecords();

		StubTable& operator= (const StubTable& other);

	private:
		std::string m_name;
		std::vector< std::unique_ptr<IField> > m_fields;
		std::unique_ptr<StubPrimaryKey> m_primaryKey;
		std::vector<std::unique_ptr<StubTableRecord> > m_tableRecords;

		FieldTypes getTypeFromSQLiteTypeName(std::string typeName);

		bool isOwned(const IField& field) const;
		std::string getSQLValue(const IFieldValue& fieldValue, bool forComparison, bool forAssignment) const;
		std::string getStringList(const std::vector<std::string>& items, const std::string& separator) const;
	};

}

