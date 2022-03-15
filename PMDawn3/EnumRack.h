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
	ADMIN,
	STANDARD
};

