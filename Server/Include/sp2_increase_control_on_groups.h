#ifndef _EHE_ACTIONS_INCREASE_CONTROL_ON_GROUPS
#define _EHE_ACTIONS_INCREASE_CONTROL_ON_GROUPS


namespace EHEActions
{


class GIncreaseControlOnGroups : public SDK::EHE::GAction
{
   // object must be cloneable (deep copy) for registration in the manager
   GIncreaseControlOnGroups* Clone() const;

   // let the entity execute the action on the specified target with the given strength
   void Execute();

	bool CheckHardConditions() const;

private:

	void ExecutePartyStatus(const GEntity* in_pEntity) const;
};


};

#endif