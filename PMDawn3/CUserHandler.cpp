#include "pch.h"
#include "CUserHandler.h"

CUserHandler* CUserEngine::GetData(UserEntities which)
{
	if (which < UserEntities::LAST && m_userH[which] != NULL)
	{
		return m_userH[which];
	}
}

bool CUserEngine::DeleteData(UserEntities which, CUserHandler* pData)
{
	if (which < UserEntities::LAST && m_userH[which] != NULL)
	{
		return m_userH[which]->DeleteData(pData);
	}
	return FALSE;
}

bool CUserEngine::PutData(UserEntities which, CUserHandler* pData)
{
	if (which < UserEntities::LAST && m_userH[which] != NULL)
	{
		return m_userH[which]->PutData(pData);
	}
	return FALSE;
}

bool CUserEngine::PostData(UserEntities which, CUserHandler* pData)
{
	if (which < UserEntities::LAST && m_userH[which] != NULL)
	{
		return m_userH[which]->PostData(pData);
	}
	return FALSE;
}
