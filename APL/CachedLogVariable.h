//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one
// or more contributor license agreements. See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  Green Enery Corp licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.
//
#ifndef __CachedLogVariable_H_
#define __CachedLogVariable_H_

#include <string>
#include <vector>
#include <map>
#include "Logger.h"


namespace apl
{
	class CachedLogVariable
	{
	public:
		CachedLogVariable(Logger* apLogger, const std::string& arName)
			: mVar(apLogger, arName),
			mCurrent(0),
			mSet(false)
		{
		}

		void Set(int aVal) {
			if ( aVal != mCurrent || !mSet) {
				mVar.Set(aVal);
				mCurrent = aVal;
				mSet = true;
			}
		}

	private:
		LogVariable mVar;
		int mCurrent;
		bool mSet;
	};
}

#endif
