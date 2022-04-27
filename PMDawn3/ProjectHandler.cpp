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

void CTask::UpdateTaskTimeStatus()
{
	if (m_iTaskTimeEstimated == m_iTaskTimeCompleted && m_CurrentStatus == TaskStatus::CLOSED)
	{
		m_TTStatus = TaskTimeStatus::COMPLETED_ON_TIME;
	}

	else if (m_iTaskTimeEstimated < m_iTaskTimeCompleted && m_CurrentStatus == TaskStatus::CLOSED)
	{
		m_TTStatus = TaskTimeStatus::COMPLETED_LATE;
	}

	else if (m_iTaskTimeEstimated > m_iTaskTimeCompleted && m_CurrentStatus == TaskStatus::CLOSED)
	{
		m_TTStatus = TaskTimeStatus::COMPLETED_PRIOR_TIME;
	}

	else if (m_iTaskTimeEstimated > m_iTaskTimeCompleted && m_CurrentStatus == TaskStatus::IN_PROGRESS)
	{
		m_TTStatus = TaskTimeStatus::INCOMPLETE_TIME_AVAILABLE;

		//If completion time >= 90% of Estimated time, then estimated time is near to end
		//So, task completion is in risk state
		if (((m_iTaskTimeCompleted / m_iTaskTimeEstimated)*100) >= 90) 
		{
			m_TTStatus = TaskTimeStatus::INCOMPLETE_TIME_RISK;
		}
	}

	else if (m_iTaskTimeEstimated < m_iTaskTimeCompleted && m_CurrentStatus == TaskStatus::IN_PROGRESS)
	{
		m_TTStatus = TaskTimeStatus::INCOMPLETE_TIME_ELAPSED;
	}
}

bool CTask::PutData(CTask* pData)
{
	bool bRes = true;
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
					bRes = false;
				}
			}
		}

		//update status
		UpdateTaskTimeStatus();
		
		//Proceed for further update in the DB data 

	}
	return bRes;
}
