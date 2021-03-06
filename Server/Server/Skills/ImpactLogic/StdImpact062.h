/********************************************************************
	created:	2008/05/04
	created:	4:5:2008   19:22
	filename: 	MapServer\Server\Skills\ImpactLogic\StdImpact062.h
	file path:	MapServer\Server\Skills\ImpactLogic
	file base:	StdImpact062
	file ext:	h
	author:		Richard
	
	purpose:	HOT
*********************************************************************/

#ifndef StdImpact062_h__
#define StdImpact062_h__

#include "ImpactLogic.h"

namespace Combat_Module
{
	namespace Impact_Module
	{
		class StdImpact062_T : public ImpactLogic_T
		{
			public:
				enum
				{
					ID = STD_IMPACT_062,
				};

				enum
				{
					REFIX_TYPE_POINT,
					REFIX_TYPE_RATE,			
					REFIX_TYPE_ME,			
					REFIX_TYPE_SENDER
				};

				enum
				{
					REFIX_PARAM_TYPE_0 = 0,			//取金攻击属性
					REFIX_PARAM_TYPE_1,				//取木攻击属性
					REFIX_PARAM_TYPE_2,				//取水攻击属性
					REFIX_PARAM_TYPE_3,				//取火攻击属性
					REFIX_PARAM_TYPE_4,				//取土攻击属性

					REFIX_PARAM_TYPE_5,				//取远程内功攻击属性
					REFIX_PARAM_TYPE_6,				//取远程外功攻击属性
					REFIX_PARAM_TYPE_7,				//取近程内功攻击属性
					REFIX_PARAM_TYPE_8,				//取近程外功攻击属性
					
					REFIX_PARAM_TYPE_MAX
				};

				class ImpactDataDescriptorIndex_T
				{
					public:
						enum
						{
							IDX_REFIX_TYPE=0,		//0为按点数修正，1为按百分比修正 , 2 为取me的某些参数 3 为取sender的某些参数
							IDX_REFIX_HP,			//
							IDX_REFIX_MP,
							IDX_REFIX_PNEUMA,
							IDX_REFIX_RAGE,
 							IDX_REFIX_RATE
						};
				};
				StdImpact062_T() {};
				~StdImpact062_T() {};
				BOOL IsOverTimed(VOID) const {return TRUE;};
				BOOL IsIntervaled(VOID) const {return TRUE;};
				BOOL InitFromData(OWN_IMPACT& rImp, ImpactData_T const& rData) const;
				
				INT GetHP(OWN_IMPACT const& rImp) const 
				{
					return rImp.GetParamByIndex(ImpactDataDescriptorIndex_T::IDX_REFIX_HP);
				}
				VOID SetHP(OWN_IMPACT& rImp, INT const nDamage) const 
				{
					rImp.SetParamByIndex(ImpactDataDescriptorIndex_T::IDX_REFIX_HP, nDamage);
				}

				INT GetMP(OWN_IMPACT const& rImp) const 
				{
					return rImp.GetParamByIndex(ImpactDataDescriptorIndex_T::IDX_REFIX_MP);
				}
				VOID SetMP(OWN_IMPACT& rImp, INT const nDamage) const 
				{
					rImp.SetParamByIndex(ImpactDataDescriptorIndex_T::IDX_REFIX_MP, nDamage);
				}

				INT GetPneuma(OWN_IMPACT const& rImp) const 
				{
					return rImp.GetParamByIndex(ImpactDataDescriptorIndex_T::IDX_REFIX_PNEUMA);
				}
				VOID SetPneuma(OWN_IMPACT& rImp, INT const nDamage) const 
				{
					rImp.SetParamByIndex(ImpactDataDescriptorIndex_T::IDX_REFIX_PNEUMA, nDamage);
				}
 
				INT GetRage(OWN_IMPACT const& rImp) const 
				{
					return rImp.GetParamByIndex(ImpactDataDescriptorIndex_T::IDX_REFIX_RAGE);
				}
				VOID SetRage(OWN_IMPACT& rImp, INT const nDamage) const 
				{
					rImp.SetParamByIndex(ImpactDataDescriptorIndex_T::IDX_REFIX_RAGE, nDamage);
				}
			public: //message handler
				VOID OnIntervalOver(OWN_IMPACT& rImp, Obj_Character& rMe) const;
				BOOL RefixPowerByRate(OWN_IMPACT& rImp, INT nRate) const;
			protected:
				VOID InitDamages( OWN_IMPACT& rImp ) const;
				INT GetRifixResult(OWN_IMPACT& rImp, Obj_Character& rMe, Obj_Character& rSender, INT iBase, INT iRefix, INT iRefixType ) const;
				INT	GetRefixParamValue(OWN_IMPACT& rImp, Obj_Character& rMe, Obj_Character& rSender, INT iRefixType, INT nParamType) const;
			private:
		} ;
	};
};

#endif // StdImpact062_h__
