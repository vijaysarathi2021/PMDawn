#pragma once

#include "CActivityLogger.h"
#include"CSystemHealthMonitor.h"
#include "DBManager.h"


/*Main Engine class integrated with logger instance*/

class CMainEngine : CActivityLogger
{
private:


	//Singleton components
	static CMainEngine* m_pMainEngine;

	CMainEngine() {}
	~CMainEngine(){}

public:
	CMainEngine* GetInstance()
	{
		if (!m_pMainEngine)
		{
			m_pMainEngine = new CMainEngine();
		}
		return m_pMainEngine;
	}

	void DeleteInstance()
	{
		if (m_pMainEngine)
		{
			delete m_pMainEngine;
			m_pMainEngine = NULL;
		}
	}

};

