#pragma once


//DB Result
enum DB_Result
{
	DB_SUCCESS,
	DB_WARNING,
	DB_ERR
};

//Activity Logger
enum Log_Severity
{
	LOG_DEBUG,
	LOG_WARNING,
	LOG_ERROR,
	LOG_FATAL
};


//System Health Monitor
enum SystemStatus
{
	HEALTHY,
	MEMORY_LOW,
	FAULTY,
	FULL_PROCESSOR_LOAD
};


//User Handler
enum UserPrevilage
{
	SUPERUSER,
	ADMIN,
	STANDARD
};


//User Entities
enum UserEntities
{
	DASHBOARD,
	UE_TASK,
	ANALYTICS,
	PROFILE,		//Creation of user profile subject to licensing/subscription - Accessible only for SuperUser
	STATUS,
	CREATE_NEW_USER,
	UE_LAST
};


//Project Handler

enum ProjectEntities
{
	PROJECT_PROFILE,
	PROJECT_CONFIG,
	PROJECT_RELEASE,
	PROJECT_ANALYTICS,
	PE_LAST
};

//Task Status
enum TaskStatus
{
	NEW,
	IN_PROGRESS,
	TRIAGE,
	CLOSED   //Keep as Last in Enum
};


enum TaskType
{
	FEATURE,
	BUG,
	TASKS     //Keep as Last in Enum
};


