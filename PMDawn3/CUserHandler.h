#pragma once

#include "EnumRack.h"
#include <vector>

/*
The user handler entity is completely responsible for features associated with users.
*/


//Base class for all User entities
class CUserHandler
{
	long m_lUserID;

public:
	CString m_strErrorMessage;

	virtual CUserHandler* GetData() { return NULL; }
	virtual bool PutData(CUserHandler* pData) = 0;
	virtual bool PostData(CUserHandler* pData) = 0;
	virtual bool DeleteData(CUserHandler* pData) = 0;
};



class CUserEngine
{
	//UserPrevilage m_UserPrevilage;
	CUserHandler *m_userH[UserEntities::LAST - 1];
public:

	CUserHandler* GetData(UserEntities which);
	bool PutData(UserEntities which, CUserHandler* pData);
	bool PostData(UserEntities which, CUserHandler* pData);
	bool DeleteData(UserEntities which, CUserHandler* pData);
};




/*
Applying Mediator Design patterns to fullfil requirements of User Entities

Dashboard 
Task
Analytics
Status
Profile

*/

/*
Entity to handle Dashboard content
Only Get exists, as Dashboard is only the view, 
Direct update is not applicable
*/
class CUserDashboardHandler : public CUserHandler
{
public:
	virtual CUserHandler* GetData() { return this; }
	virtual bool PutData(CUserHandler* pData) { return false; }
	virtual bool PostData(CUserHandler* pData) { return false; }
	virtual bool DeleteData(CUserHandler* pData) { return false; }
	
};


/*
Entity to handle Task/Assignment content
*/
class CUserTaskHandler : public CUserHandler
{

public:
	virtual CUserHandler* GetData() { return this; }
	virtual bool PutData(CUserHandler* pData) { return true; }
	virtual bool PostData(CUserHandler* pData) { return true; }
	virtual bool DeleteData(CUserHandler* pData) { return true; }
};


class CUserAnalyticsHandler : public CUserHandler
{
public:
	virtual CUserHandler* GetData() { return this; }
	virtual bool PutData(CUserHandler* pData) { return true; }
	virtual bool PostData(CUserHandler* pData) { return true; }
	virtual bool DeleteData(CUserHandler* pData) { return true; }

};


class CUserStatusHandler : public CUserHandler
{
public:
	virtual CUserHandler* GetData() { return this; }
	virtual bool PutData(CUserHandler* pData) { return true; }
	virtual bool PostData(CUserHandler* pData) { return true; }
	virtual bool DeleteData(CUserHandler* pData) { return true; }
};


class CUserProfileHandler : public CUserHandler
{

public:
	virtual CUserHandler* GetData() { return this; }
	virtual bool PutData(CUserHandler* pData) { return true; }
	virtual bool PostData(CUserHandler* pData) { return true; }
	virtual bool DeleteData(CUserHandler* pData) { return true; }
};


class CUserCreateHandler : public CUserHandler
{

public:
	
	//CUserHandler* GetData() { return this; }
	virtual bool PutData(CUserHandler* pData) { return true; }
	virtual bool PostData(CUserHandler* pData) { return true; }
	virtual bool DeleteData(CUserHandler* pData) { return true; }
};


