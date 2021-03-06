//
// Created by kjell-olovhogdahl on 7/27/2016.
//

#ifndef CLANG_BCC_FRONTEND_H
#define CLANG_BCC_FRONTEND_H

/**
 * This is the FrontEnd in the Frontend-Core-Backend source code architecture idiom.
 *
	FrontEnd.cpp	<—	FronEnd.h	—>	FrontEndImpl.h	->	FrontEndImpl.cpp
	    ^					            ^
	    |----------------------			    |
			  	  |			    |
	Core.cpp	<—	Core.h		->	CoreImpl.h	->	CoreImpl.cpp
	    ^						    ^
	    |----------------------			    |
			  	  |			    |

	BackEnd.cpp	<—	BackEnd.h	->	BackendImpl.h	->	BackendImpl.cpp
	    ^			\___________________________________/		      ^
	    |					 |				      |
	    |				     Isolated				      |
	    |									      |
	    ---------------------------------------------------------------------------
						 |
					Build Environment
					    Platform
 */

#include "BackEnd.h"

namespace frontend {

    struct Console {}; // Console tag

    template <typename Tag>
    class FrontEnd { // Primary template class never used
        static_assert(true,"Provided Frontend tag not supported");
    };

    template <>
    class FrontEnd<Console>  { // The Console Frontend
    public:
        FrontEnd(const backend::API_STRING& sExe);
		~FrontEnd();
        FrontEnd(const FrontEnd&) = delete;
        FrontEnd& operator=(const FrontEnd&)= delete;
        int run();

    private:
		struct impl;
        std::unique_ptr<impl> m_pimpl;
    };
}

#endif //CLANG_BCC_FRONTEND_H
