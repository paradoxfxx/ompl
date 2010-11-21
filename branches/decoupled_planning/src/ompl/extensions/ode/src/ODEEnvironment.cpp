/*********************************************************************
* Software License Agreement (BSD License)
* 
*  Copyright (c) 2010, Rice University
*  All rights reserved.
* 
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
* 
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*   * Neither the name of the Rice University nor the names of its
*     contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
* 
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*********************************************************************/

/* Author: Ioan Sucan */

#include "ompl/extensions/ode/ODEEnvironment.h"
#include <boost/lexical_cast.hpp>

unsigned int ompl::control::ODEEnvironment::getMaxContacts(dGeomID geom1, dGeomID geom2) const
{
    return maxContacts_;
}

bool ompl::control::ODEEnvironment::isValidCollision(dGeomID geom1, dGeomID geom2, const dContact& contact) const
{
    return false;
}

void ompl::control::ODEEnvironment::setupContact(dContact &contact) const
{
    contact.surface.mode = dContactBounce | dContactSoftCFM;
    contact.surface.mu = 0.1;
    contact.surface.mu2 = 0;
    contact.surface.bounce = 0.01;
    contact.surface.bounce_vel = 0.001;
    contact.surface.soft_cfm = 0.01;
}

std::string ompl::control::ODEEnvironment::getGeomName(dGeomID geom) const
{
    std::map<dGeomID, std::string>::const_iterator it = geomNames_.find(geom);
    if (it == geomNames_.end())
        return boost::lexical_cast<std::string>(geom);
    else
        return it->second;
}

void ompl::control::ODEEnvironment::setGeomName(dGeomID geom, const std::string &name)
{
    geomNames_[geom] = name;
}