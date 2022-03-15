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
