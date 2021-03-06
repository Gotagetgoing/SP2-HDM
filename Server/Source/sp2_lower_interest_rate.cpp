#include "golem_pch.hpp"


using namespace EHEActions;


GLowerInterestRate* GLowerInterestRate::Clone() const
{
   return new GLowerInterestRate( *this ); 
}


void GLowerInterestRate::Execute()
{
   // modification is capped between 0.01% and 5%
   // a strenght of 1 == a modification of 1%

	GEntity* pEntity = GManager::Entity( m_iSource );
	if ( ! pEntity ) return;

   REAL32 l_fInterest = 0.0f;
   REAL32 l_fInterestModif = 0.0f;

	l_fInterest = g_ServerDAL.CountryData(m_iSource)->InterestLevel();

	if(l_fInterest > SP2::InterestRate_LowerCap) 
   {
      l_fInterestModif = m_fStrength*EHEConstants::InterestRate_Normal;

      if(l_fInterestModif < EHEConstants::InterestRate_Min)
         l_fInterestModif = EHEConstants::InterestRate_Min;
      if(l_fInterestModif > EHEConstants::InterestRate_Max)
         l_fInterestModif = EHEConstants::InterestRate_Max;

		REAL32 l_fNewInterest = l_fInterest - l_fInterestModif;

		g_ServerDCL.ChangeInterestRate(m_iSource,l_fInterest,l_fNewInterest);
   }   
	else
		g_Joshua.Log(pEntity->Description() + L" cannot lower its Interest Level any more.", MSGTYPE_MSG);
}

bool GLowerInterestRate::CheckHardConditions() const
{
	if (g_ServerDAL.CountryData(m_iSource)->InterestLevel() <= SP2::InterestRate_LowerCap)
		return false;

	return true;
}