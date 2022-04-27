#pragma once

#include "EnumRack.h"
#include <vector>
#include "ProjectHandler.h"
#include <string>
/*
The user handler entity is completely responsible for features associated with users.
*/


//Base class for all User entities
class CUserHandler
{
	std::vector<CTask> m_vecTaskList;   //User Tasks
	std::vector<int> m_vecProjectList;	//Project associated for the user

public:
	long m_lUserID;
	CString m_strErrorMessage;

	virtual CUserHandler* GetData() { return NULL; }
	virtual bool PutData(CUserHandler* pData) = 0;
	virtual bool PostData(CUserHandler* pData) = 0;
	virtual bool DeleteData(CUserHandler* pData) = 0;
};


//Mediator design pattern Entity
class CUserEngine
{
	//UserPrevilage m_UserPrevilage;
	CUserHandler *m_userH[UserEntities::UE_LAST - 1];

public:
	bool ValidateInput(CUserHandler* pData);

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


/*
Entity to handle and calculate analytics content like user productivity, work hours etc.,
*/
class CUserAnalyticsHandler : public CUserHandler
{
public:
	virtual CUserHandler* GetData() { return this; }
	/*
	virtual bool PutData(CUserHandler* pData) { return true; }
	virtual bool PostData(CUserHandler* pData) { return true; }
	virtual bool DeleteData(CUserHandler* pData) { return true; }
	*/

};

/*
Entity to get the current status of the given user.
*/
class CUserStatusHandler : public CUserHandler
{
public:
	virtual CUserHandler* GetData() { return this; }
	virtual bool PutData(CUserHandler* pData) { return true; }
	virtual bool PostData(CUserHandler* pData) { return true; }
	virtual bool DeleteData(CUserHandler* pData) { return true; }
};


/*
Entity to maintain the user profile information
*/
class CUserProfileHandler : public CUserHandler
{
	std::string m_strUserName;
	std::vector<std::string> m_Project;	//User mapping in the project

public:
	virtual CUserHandler* GetData() { return this; }
	virtual bool PutData(CUserHandler* pData) { return true; }
	virtual bool PostData(CUserHandler* pData) { return true; }		//Method used to create new User Profile
	virtual bool DeleteData(CUserHandler* pData) { return true; }
};


