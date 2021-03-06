/*
 * thd_sysfs_intel_pstate_driver.h: thermal cooling class interface
 *	using Intel p state driver
 * Copyright (C) 2012 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 or later as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 *
 * Author Name <Srinivas.Pandruvada@linux.intel.com>
 *
 */

#ifndef THD_CDEV_INTEL_PSATATE_DRIVER_H_
#define THD_CDEV_INTEL_PSATATE_DRIVER_H_

#include "thd_cdev.h"
#include "thd_msr.h"

class cthd_intel_p_state_cdev: public cthd_cdev
{
private:
	cthd_msr msr;

	int highest_turbo_freq_state;
	int lowest_freq_state;
	int lowest_turbo_freq_state;
	float unit_value;
	int min_compensation;
	int max_offset;

public:
	static const int intel_pstate_limit_ratio = 2;
	static const int default_max_state = 10;
	cthd_intel_p_state_cdev(unsigned int _index, std::string control_path)
		: cthd_cdev(_index, control_path), unit_value(1), min_compensation(0), max_offset(0) {};
	void set_curr_state(int state, int arg);
	int get_max_state();
	int update();
};


#endif /* THD_CDEV_INTEL_PSATATE_DRIVER_H_ */
