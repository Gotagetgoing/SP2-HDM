#ifndef _EHE_ACTIONS_INCREASE_CONTROL_ON_COUNTRY
#define _EHE_ACTIONS_INCREASE_CONTROL_ON_COUNTRY


namespace EHEActions
{


class GIncreaseControlOnCountry : public SDK::EHE::GAction
{
   // object must be cloneable (deep copy) for registration in the manager
   GIncreaseControlOnCountry* Clone() const;

   // let the entity execute the action on the specified target with the given strength
   void Execute();

	bool CheckHardConditions() const;
};


};

#endif