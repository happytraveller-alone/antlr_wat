
// Generated from StrLexer.g4 by ANTLR 4.13.1


#include "StrLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct StrLexerStaticData final {
  StrLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  StrLexerStaticData(const StrLexerStaticData&) = delete;
  StrLexerStaticData(StrLexerStaticData&&) = delete;
  StrLexerStaticData& operator=(const StrLexerStaticData&) = delete;
  StrLexerStaticData& operator=(StrLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag strlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
StrLexerStaticData *strlexerLexerStaticData = nullptr;

void strlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (strlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(strlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<StrLexerStaticData>(
    std::vector<std::string>{
      "Digit", "Letter", "LOWERLETTER", "KEY", "DIGIT", "LETTER", "LPAR", 
      "RPAR", "LBRACE", "RBRACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'visit'", "", "", "'('", "')'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "KEY", "DIGIT", "LETTER", "LPAR", "RPAR", "LBRACE", "RBRACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,7,45,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
  	2,7,7,7,2,8,7,8,2,9,7,9,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,0,0,10,1,0,3,0,5,0,
  	7,1,9,2,11,3,13,4,15,5,17,6,19,7,1,0,3,1,0,48,57,2,0,65,90,97,122,1,0,
  	97,122,41,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,
  	0,0,0,17,1,0,0,0,0,19,1,0,0,0,1,21,1,0,0,0,3,23,1,0,0,0,5,25,1,0,0,0,
  	7,27,1,0,0,0,9,33,1,0,0,0,11,35,1,0,0,0,13,37,1,0,0,0,15,39,1,0,0,0,17,
  	41,1,0,0,0,19,43,1,0,0,0,21,22,7,0,0,0,22,2,1,0,0,0,23,24,7,1,0,0,24,
  	4,1,0,0,0,25,26,7,2,0,0,26,6,1,0,0,0,27,28,5,118,0,0,28,29,5,105,0,0,
  	29,30,5,115,0,0,30,31,5,105,0,0,31,32,5,116,0,0,32,8,1,0,0,0,33,34,3,
  	1,0,0,34,10,1,0,0,0,35,36,3,5,2,0,36,12,1,0,0,0,37,38,5,40,0,0,38,14,
  	1,0,0,0,39,40,5,41,0,0,40,16,1,0,0,0,41,42,5,123,0,0,42,18,1,0,0,0,43,
  	44,5,125,0,0,44,20,1,0,0,0,1,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  strlexerLexerStaticData = staticData.release();
}

}

StrLexer::StrLexer(CharStream *input) : Lexer(input) {
  StrLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *strlexerLexerStaticData->atn, strlexerLexerStaticData->decisionToDFA, strlexerLexerStaticData->sharedContextCache);
}

StrLexer::~StrLexer() {
  delete _interpreter;
}

std::string StrLexer::getGrammarFileName() const {
  return "StrLexer.g4";
}

const std::vector<std::string>& StrLexer::getRuleNames() const {
  return strlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& StrLexer::getChannelNames() const {
  return strlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& StrLexer::getModeNames() const {
  return strlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& StrLexer::getVocabulary() const {
  return strlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView StrLexer::getSerializedATN() const {
  return strlexerLexerStaticData->serializedATN;
}

const atn::ATN& StrLexer::getATN() const {
  return *strlexerLexerStaticData->atn;
}




void StrLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  strlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(strlexerLexerOnceFlag, strlexerLexerInitialize);
#endif
}
