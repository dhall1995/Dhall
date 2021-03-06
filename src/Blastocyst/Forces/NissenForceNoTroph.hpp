#ifndef NISSENFORCENOTROPH_HPP_
#define NISSENFORCENOTROPH_HPP_

#include "AbstractTwoBodyInteractionForce.hpp"

#include "ChasteSerialization.hpp"
#include <boost/serialization/base_object.hpp>

// NOTE: It is not a good idea to include "Test" in a class name, to avoid confusion with test suite names.

template<unsigned  ELEMENT_DIM, unsigned SPACE_DIM=ELEMENT_DIM>
class NissenForceNoTroph : public AbstractTwoBodyInteractionForce<ELEMENT_DIM, SPACE_DIM>
{
private:

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<AbstractTwoBodyInteractionForce<ELEMENT_DIM, SPACE_DIM> >(*this);
        archive & mS_ICM_ICM;;
        archive & mS_PrE_PrE;
        archive & mS_PrE_EPI;
        archive & mS_PrE_ICM;
        archive & mS_EPI_EPI;
        archive & mS_EPI_ICM;
        archive & mGrowthDuration;
    }

    // Define all the relevant attraction factors for our force law
    double mS_ICM_ICM;
    double mS_PrE_PrE;
    double mS_PrE_EPI;
    double mS_PrE_ICM;
    double mS_EPI_EPI;
    double mS_EPI_ICM;
    double mGrowthDuration;

public:

    NissenForceNoTroph();

    virtual ~NissenForceNoTroph();

    c_vector<double, SPACE_DIM> CalculateForceBetweenNodes(unsigned nodeAGlobalIndex,
                                                           unsigned nodeBGlobalIndex,
                                                           AbstractCellPopulation<ELEMENT_DIM,SPACE_DIM>& rCellPopulation);

    double GetS_ICM_ICM();
    void SetS_ICM_ICM(double s);
    
    double GetS_PrE_PrE();
    void SetS_PrE_PrE(double s);
    
    double GetS_PrE_EPI();
    void SetS_PrE_EPI(double s);
    
    double GetS_PrE_ICM();
    void SetS_PrE_ICM(double s);
    
    double GetS_EPI_EPI();
    void SetS_EPI_EPI(double s);
    
    double GetS_EPI_ICM();
    void SetS_EPI_ICM(double s);
    
    double GetGrowthDuration();
    void SetGrowthDuration(double GrowthDuration);

    virtual void OutputForceParameters(out_stream& rParamsFile);
};

#include "SerializationExportWrapper.hpp"
EXPORT_TEMPLATE_CLASS_ALL_DIMS(NissenForceNoTroph)

#endif /*NISSENFORCENOTROPH_HPP_*/
