#pragma once

#include "Core/ELF/ElfRelocator.h"


class Z80ElfRelocator: public IElfRelocator
{
public:
	int expectedMachine() const override { return 0; }
	bool relocateOpcode(int type, const RelocationData& data, std::vector<RelocationAction>& actions, std::vector<std::string>& errors) override { return false; }
	bool finish(std::vector<RelocationAction>& actions, std::vector<std::string>& errors) override { return false; }
	void setSymbolAddress(RelocationData& data, int64_t symbolAddress, int symbolType) override { return; }
	std::unique_ptr<CAssemblerCommand> generateCtorStub(std::vector<ElfRelocatorCtor>& ctors) override { return nullptr; }
};
