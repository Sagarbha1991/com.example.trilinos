#ifndef MUELU_DEFAULTFACTORYHANDLER_HPP
#define MUELU_DEFAULTFACTORYHANDLER_HPP

#include "MueLu_ConfigDefs.hpp"
#include "MueLu_Exceptions.hpp"

#include "MueLu_DefaultFactoryHandlerBase.hpp"

// Default factories:
#include "MueLu_UCAggregationFactory.hpp"

namespace MueLu {

  //! Class that provides default factories within Needs class.
  template<class Scalar, class LocalOrdinal, class GlobalOrdinal, class Node, class LocalMatOps>
  class DefaultFactoryHandler : public DefaultFactoryHandlerBase {

#include "MueLu_UseShortNames.hpp"

  public:
    //@{ Constructors/Destructors.

    //! Constructor.
    DefaultFactoryHandler() {}

    //! Destructor.
    virtual ~DefaultFactoryHandler() { }

    //@}
    
    //@{ Get/Set functions.

    virtual const RCP<FactoryBase> & GetDefaultFactory(const std::string & varName) {
      if (! DefaultFactoryHandlerBase::IsAvailable(varName)) {

        if (varName == "Aggregates") {
          return SetAndReturnDefaultFactory(varName, rcp(new UCAggregationFactory()));
        }

        TEST_FOR_EXCEPTION(1, MueLu::Exceptions::RuntimeError, "DefaultFactoryHandler::GetDefaultFactory(): No default factory available for building '"+varName+"'.");

      }

      return DefaultFactoryHandlerBase::GetDefaultFactory(varName);
    }

    //@}
    
  private:

    //! helper
    const RCP<FactoryBase> & SetAndReturnDefaultFactory(const std::string & varName, const RCP<FactoryBase> factory) {
      DefaultFactoryHandlerBase::SetDefaultFactory(varName, factory);
      return DefaultFactoryHandlerBase::GetDefaultFactory(varName); //return factory;
    }

  }; // class DefaultFactoryHandler

} // namespace MueLu

#define MUELU_DEFAULTFACTORYHANDLER_SHORT
#endif //ifndef MUELU_DEFAULTFACTORYHANDLER_HPP
