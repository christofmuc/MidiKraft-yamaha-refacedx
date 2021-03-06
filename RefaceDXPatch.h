/*
   Copyright (c) 2020 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#pragma once

#include "Patch.h"
#include "StoredPatchNameCapability.h"

namespace midikraft {

	class RefaceDXPatch : public Patch, public StoredPatchNameCapability, public DefaultNameCapability {
	public:
		typedef struct { std::vector<uint8> common; std::vector<uint8> op[4]; int count;  } TVoiceData;

		RefaceDXPatch(Synth::PatchData const &voiceData, MidiProgramNumber place);

		virtual std::string name() const override;

		// StoredPatchNameCapability
		virtual void setName(std::string const &name) override;

		// DefaultNameCapability
		virtual bool isDefaultName(std::string const &patchName) const override;

		virtual MidiProgramNumber patchNumber() const override;

	private:
		friend class RefaceDX;
		MidiProgramNumber originalProgramNumber_;
	};

}
