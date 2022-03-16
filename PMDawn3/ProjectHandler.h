#pragma once

#include "EnumRack.h"
#include<vector>



//Forward Declaration
class CTask;
class CProjectSprint;



/*
Base class for all project related entities
*/
class CProjectHandler
{
	//Possibility of Project handled at multiple world regions
	long m_lProjectID;
	long m_lRegion;
public:
	CString m_strErrorMessage;

	bool ValidateInput(CProjectHandler* pData);
	
	virtual CProjectHandler* GetData() { return NULL; }
	virtual bool PutData(CProjectHandler* pData) = 0;
	virtual bool PostData(CProjectHandler* pData) = 0;		//Reused to create New Project
	virtual bool DeleteData(CProjectHandler* pData) = 0;
};


class CProjectEngine
{
	CProjectHandler* m_ProjectH[PE_LAST - 1];

public:
	bool ValidateInput(CProjectHandler* pData);

	CProjectHandler* GetData(ProjectEntities which);
	bool PutData(ProjectEntities which, CProjectHandler* pData);
	bool PostData(ProjectEntities which, CProjectHandler* pData);
	bool DeleteData(ProjectEntities which, CProjectHandler* pData);
};


//Well suited for Agile, 
//In case of waterfall, the sprint will be only 1.
class CProjectRelease : public CProjectHandler
{
	long m_lProjectID;
	long m_lRegionID;
	long m_lReleaseID;
	long m_lReleaseVersion;

	std::vector<CString> m_ReleaseNotes;


	std::vector<CProjectSprint> m_vecSprints;
};


class CProjectSprint
{
	long m_lSprintID;
	long m_lReleaseID;

	std::vector<CTask> m_vecTasks;
};

/*
Entity to handle and calculate analytics content like Project productivity, 
progress rate, tentative end date, duration etc.,
*/
class CProjectAnalytics : public CProjectHandler
{
	std::vector<CProjectSprint> m_vecSprintReport;
	DATE m_AutoCalculatedEndDate;
	float m_fProjectProgressRate;
	float m_fTentativeDuration;
};


/*
Entity to handle Project related configurations
*/
class CProjectConfig: public CProjectHandler
{
	std::vector<std::pair<long, CString>> m_lProjectMembers;	//Permitted member for a project
	
	long m_duration;

	DATE m_StartDate;
	DATE m_TargetEndDate;
	DATE m_EndDate;

	float m_fProgress;
	CProjectAnalytics* m_pAnalytics;
};



/*Project profile - Consists of general details of the project*/
class CProjectProfile :public CProjectHandler
{
	long m_lUserID;		//User who is performing project changes
	long m_lTaskCount;
	long m_lSubProjectCount;

	CString m_strProjectTitle;
	CString m_strProjectDescription;
	
	CProjectConfig* m_pProjectConfig;

	std::vector<CProjectProfile> m_vecSubProjects;
	std::vector<CTask> m_vecTasks;
	std::vector<CProjectRelease> m_vecReleases;

public:
	bool ValidateInput(CProjectHandler* pData);

	virtual CProjectHandler* GetData() { return this; }
	virtual bool PutData(CProjectHandler* pData) { return true; }
	virtual bool PostData(CProjectHandler* pData) { return true; }		//Reused to create New Project
	virtual bool DeleteData(CProjectHandler* pData) { return true; }    //User Permission must be validated before delete
};


/*Entity consists of the comments associated for the given task ID*/
class CTaskComments
{
	long m_lCommentID;
	long m_lUserId;
	long m_lTaskId;

	CString m_strComments;
	bool m_bHighlight;

	std::vector<CTaskComments> m_TaskComment;  //Addressing Sub comments
public:
};


/*Entity consists of Task/Assigment/work items for the user*/
class CTask //: public CProjectHandler
{
	long m_lTaskId;
	long m_lProjectID;
	long m_lRegionID;
	long m_lSprintID;
	long m_lParentTaskID; //Applicable only for sub task (-1 for Parent Task)
	long m_lSubTaskCount;

	CString m_strTaskTitle;
	CString m_strTaskDescription;
	CString m_strErrorMessage;

	std::vector<CTask> m_SubTaskList;
	
	TaskStatus m_CurrentStatus;
	TaskType m_Type;
	
	int m_iStoryPoints;
	
	std::vector<CTaskComments> m_vecTaskComments;

public:
	virtual bool ValidateInput(CTask* pData);

	virtual CTask* GetData() { return this; }
	virtual bool PutData(CTask* pData);// { return true; }
	virtual bool PostData(CTask* pData) { return true; }		//Reused to create New Project
	virtual bool DeleteData(CTask* pData) { return true; }    //User Permission must be validated before delete
};
