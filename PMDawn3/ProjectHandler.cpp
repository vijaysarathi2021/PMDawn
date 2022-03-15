#include "pch.h"
#include "ProjectHandler.h"

bool CProjectHandler::ValidateInput(CProjectHandler* pData)
{
	//Include associated validations
	if (m_lProjectID > 0)
	{
		return true;
	}
    return false;
}

bool CTask::PutData(CTask* pData)
{
	if (pData)
	{
		//Validation for Closing the Task - All sub task must be closed
		if (pData->m_CurrentStatus == TaskStatus::CLOSED)
		{
			//Validate whether all the sub tasks are closed
			int iSubtask = m_SubTaskList.size();

			while (iSubtask-- >= 0)
			{
				if (pData->m_SubTaskList[iSubtask].m_CurrentStatus != TaskStatus::CLOSED)
				{
					m_strErrorMessage.AppendFormat(L"\nSub Task - %d isn't in 'Closed' state", 
						pData->m_SubTaskList[iSubtask].m_lTaskId);
					return false;
				}
			}
		}

	}
	return true;
}
