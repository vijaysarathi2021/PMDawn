#pragma once
#include "EnumRack.h"
/*System Health Monitor Entity for system report and maintenance decision*/

struct SystemHealthReport
{
	SystemStatus m_SystemSts;
	SYSTEM_INFO m_Sysinfo;		//Win32 structure to get system info
};

class CSystemHealthMonitor
{
	SystemHealthReport m_Report;

public:
	/*Thread to monitor system health consistently and generate report*/
	void MonitorThread(){}	

	SystemHealthReport GetHealthReport()
	{
		return m_Report;
	}
};

