#pragma once

#include "EnumRack.h"

/*
SINGLETON DATABASE HANDLER for DB INTERACTION
*/
class CDBManager
{
private:
	//
	int m_LastExecutionError;
	


	//Singleton components
	static CDBManager* m_DBInstance;

	CDBManager() {}
	~CDBManager() {}

public:
	CDBManager* GetInstance()
	{
		if (!m_DBInstance)
		{
			m_DBInstance = new CDBManager();
		}
		return m_DBInstance;
	}

	void DeleteInstance()
	{
		if (m_DBInstance)
		{
			delete m_DBInstance;
			m_DBInstance = NULL;
		}
	}

	DB_Result Execute(const char* pchQuery)
	{
		return DB_Result::DB_SUCCESS;
	}

	int GetDBLastErrorcode()
	{
		return m_LastExecutionError;
	}

	/*
	If Error code supplied, then respective description is returned
	Otherwise, last error code description will be returned
	*/
	char* GetErrorDescription(int iErrorCode = -1);
};

