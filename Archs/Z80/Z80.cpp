#include "Archs/Z80/CZ80Instruction.h"
#include "Archs/Z80/Z80.h"
#include "Archs/Z80/Z80ElfRelocator.h"
#include "Archs/Z80/Z80Parser.h"
#include "Parser/Parser.h"

CZ80Architecture Z80;

CZ80Architecture::CZ80Architecture()
{
	this->Version = Z80ArchType::MARCH_Invalid;
}

std::unique_ptr<CAssemblerCommand> CZ80Architecture::parseDirective(Parser& parser)
{
	Z80Parser Z80Parser;

	return Z80Parser.parseDirective(parser);
}

std::unique_ptr<CAssemblerCommand> CZ80Architecture::parseOpcode(Parser& parser)
{
	Z80Parser Z80Parser;

	return Z80Parser.parseOpcode(parser);
}

std::unique_ptr<IElfRelocator> CZ80Architecture::getElfRelocator()
{
	switch (Version)
	{
	default:
		return nullptr;
	}
	return std::make_unique<Z80ElfRelocator>();
}
