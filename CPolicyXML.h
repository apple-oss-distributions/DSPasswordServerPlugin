/*
 * Copyright (c) 2003 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#ifndef __CPOLICYXML__
#define __CPOLICYXML__

#ifdef __cplusplus
extern "C" {
#endif

#include <PasswordServer/CPolicyBase.h>

// C API
int ConvertXMLPolicyToSpaceDelimited( const char *inXMLDataStr, char **outPolicyStr );
int ConvertSpaceDelimitedPolicyToXML( const char *inPolicyStr, char **outXMLDataStr );
void GetDefaultUserPolicies( PWAccessFeatures *inOutUserPolicies );

#ifdef __cplusplus
};
#endif

class CPolicyXML : public CPolicyBase
{
	public:
	
												CPolicyXML();
												CPolicyXML( CFDictionaryRef inPolicyDict );
												CPolicyXML( const char *xmlDataStr );
		virtual									~CPolicyXML();
		
		virtual void							CPolicyCommonInit( void );
		static void								CPolicyXMLCommonInitStatic( PWAccessFeatures *inOutPolicies );
		virtual void							GetPolicy( PWAccessFeatures *outPolicy );
		virtual char *							GetPolicyAsSpaceDelimitedData( void );
		virtual void							SetPolicy( PWAccessFeatures *inPolicy );
		virtual void							SetPolicy( CFDictionaryRef inPolicyDict );
		
	protected:
		
		virtual int								ConvertPropertyListPolicyToStruct( CFMutableDictionaryRef inPolicyDict );
		virtual int								ConvertStructToPropertyListPolicy( void );
		
		PWAccessFeatures mPolicy;
};


#endif

