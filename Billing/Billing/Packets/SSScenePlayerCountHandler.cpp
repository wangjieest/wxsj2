#include "stdafx.h"
#include "SSScenePlayerCount.h"



UINT SSScenePlayerCountHandler::Execute(SSScenePlayerCount* pPacket, Player* pPlayer )
{
	__ENTER_FUNCTION	
	
		return PACKET_EXE_CONTINUE;

	__LEAVE_FUNCTION	

		return PACKET_EXE_ERROR;
}