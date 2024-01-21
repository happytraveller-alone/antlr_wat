
// Generated from StrParser.g4 by ANTLR 4.13.1


#include "StrParserListener.h"
#include "StrParserVisitor.h"

#include "StrParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct StrParserStaticData final {
  StrParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  StrParserStaticData(const StrParserStaticData&) = delete;
  StrParserStaticData(StrParserStaticData&&) = delete;
  StrParserStaticData& operator=(const StrParserStaticData&) = delete;
  StrParserStaticData& operator=(StrParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag strparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
StrParserStaticData *strparserParserStaticData = nullptr;

void strparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (strparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(strparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<StrParserStaticData>(
    std::vector<std::string>{
      "left", "middle", "right", "module"
    },
    std::vector<std::string>{
      "", "'visit'", "", "", "'('", "')'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "KEY", "DIGIT", "LETTER", "LPAR", "RPAR", "LBRACE", "RBRACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,7,32,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,1,0,4,0,11,8,0,11,0,12,0,
  	12,1,0,1,0,1,1,1,1,1,2,1,2,4,2,21,8,2,11,2,12,2,22,1,2,1,2,1,3,1,3,1,
  	3,1,3,1,3,1,3,0,0,4,0,2,4,6,0,0,29,0,8,1,0,0,0,2,16,1,0,0,0,4,18,1,0,
  	0,0,6,26,1,0,0,0,8,10,5,4,0,0,9,11,5,2,0,0,10,9,1,0,0,0,11,12,1,0,0,0,
  	12,10,1,0,0,0,12,13,1,0,0,0,13,14,1,0,0,0,14,15,5,5,0,0,15,1,1,0,0,0,
  	16,17,5,1,0,0,17,3,1,0,0,0,18,20,5,6,0,0,19,21,5,3,0,0,20,19,1,0,0,0,
  	21,22,1,0,0,0,22,20,1,0,0,0,22,23,1,0,0,0,23,24,1,0,0,0,24,25,5,7,0,0,
  	25,5,1,0,0,0,26,27,3,0,0,0,27,28,3,2,1,0,28,29,3,4,2,0,29,30,5,0,0,1,
  	30,7,1,0,0,0,2,12,22
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  strparserParserStaticData = staticData.release();
}

}

StrParser::StrParser(TokenStream *input) : StrParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

StrParser::StrParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  StrParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *strparserParserStaticData->atn, strparserParserStaticData->decisionToDFA, strparserParserStaticData->sharedContextCache, options);
}

StrParser::~StrParser() {
  delete _interpreter;
}

const atn::ATN& StrParser::getATN() const {
  return *strparserParserStaticData->atn;
}

std::string StrParser::getGrammarFileName() const {
  return "StrParser.g4";
}

const std::vector<std::string>& StrParser::getRuleNames() const {
  return strparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& StrParser::getVocabulary() const {
  return strparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView StrParser::getSerializedATN() const {
  return strparserParserStaticData->serializedATN;
}


//----------------- LeftContext ------------------------------------------------------------------

StrParser::LeftContext::LeftContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StrParser::LeftContext::LPAR() {
  return getToken(StrParser::LPAR, 0);
}

tree::TerminalNode* StrParser::LeftContext::RPAR() {
  return getToken(StrParser::RPAR, 0);
}

std::vector<tree::TerminalNode *> StrParser::LeftContext::DIGIT() {
  return getTokens(StrParser::DIGIT);
}

tree::TerminalNode* StrParser::LeftContext::DIGIT(size_t i) {
  return getToken(StrParser::DIGIT, i);
}


size_t StrParser::LeftContext::getRuleIndex() const {
  return StrParser::RuleLeft;
}

void StrParser::LeftContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StrParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeft(this);
}

void StrParser::LeftContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StrParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeft(this);
}


std::any StrParser::LeftContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StrParserVisitor*>(visitor))
    return parserVisitor->visitLeft(this);
  else
    return visitor->visitChildren(this);
}

StrParser::LeftContext* StrParser::left() {
  LeftContext *_localctx = _tracker.createInstance<LeftContext>(_ctx, getState());
  enterRule(_localctx, 0, StrParser::RuleLeft);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(8);
    match(StrParser::LPAR);
    setState(10); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(9);
      match(StrParser::DIGIT);
      setState(12); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == StrParser::DIGIT);
    setState(14);
    match(StrParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MiddleContext ------------------------------------------------------------------

StrParser::MiddleContext::MiddleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StrParser::MiddleContext::KEY() {
  return getToken(StrParser::KEY, 0);
}


size_t StrParser::MiddleContext::getRuleIndex() const {
  return StrParser::RuleMiddle;
}

void StrParser::MiddleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StrParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMiddle(this);
}

void StrParser::MiddleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StrParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMiddle(this);
}


std::any StrParser::MiddleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StrParserVisitor*>(visitor))
    return parserVisitor->visitMiddle(this);
  else
    return visitor->visitChildren(this);
}

StrParser::MiddleContext* StrParser::middle() {
  MiddleContext *_localctx = _tracker.createInstance<MiddleContext>(_ctx, getState());
  enterRule(_localctx, 2, StrParser::RuleMiddle);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(16);
    match(StrParser::KEY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RightContext ------------------------------------------------------------------

StrParser::RightContext::RightContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* StrParser::RightContext::LBRACE() {
  return getToken(StrParser::LBRACE, 0);
}

tree::TerminalNode* StrParser::RightContext::RBRACE() {
  return getToken(StrParser::RBRACE, 0);
}

std::vector<tree::TerminalNode *> StrParser::RightContext::LETTER() {
  return getTokens(StrParser::LETTER);
}

tree::TerminalNode* StrParser::RightContext::LETTER(size_t i) {
  return getToken(StrParser::LETTER, i);
}


size_t StrParser::RightContext::getRuleIndex() const {
  return StrParser::RuleRight;
}

void StrParser::RightContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StrParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRight(this);
}

void StrParser::RightContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StrParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRight(this);
}


std::any StrParser::RightContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StrParserVisitor*>(visitor))
    return parserVisitor->visitRight(this);
  else
    return visitor->visitChildren(this);
}

StrParser::RightContext* StrParser::right() {
  RightContext *_localctx = _tracker.createInstance<RightContext>(_ctx, getState());
  enterRule(_localctx, 4, StrParser::RuleRight);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    match(StrParser::LBRACE);
    setState(20); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(19);
      match(StrParser::LETTER);
      setState(22); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == StrParser::LETTER);
    setState(24);
    match(StrParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleContext ------------------------------------------------------------------

StrParser::ModuleContext::ModuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

StrParser::LeftContext* StrParser::ModuleContext::left() {
  return getRuleContext<StrParser::LeftContext>(0);
}

StrParser::MiddleContext* StrParser::ModuleContext::middle() {
  return getRuleContext<StrParser::MiddleContext>(0);
}

StrParser::RightContext* StrParser::ModuleContext::right() {
  return getRuleContext<StrParser::RightContext>(0);
}

tree::TerminalNode* StrParser::ModuleContext::EOF() {
  return getToken(StrParser::EOF, 0);
}


size_t StrParser::ModuleContext::getRuleIndex() const {
  return StrParser::RuleModule;
}

void StrParser::ModuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StrParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule(this);
}

void StrParser::ModuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<StrParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule(this);
}


std::any StrParser::ModuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<StrParserVisitor*>(visitor))
    return parserVisitor->visitModule(this);
  else
    return visitor->visitChildren(this);
}

StrParser::ModuleContext* StrParser::module() {
  ModuleContext *_localctx = _tracker.createInstance<ModuleContext>(_ctx, getState());
  enterRule(_localctx, 6, StrParser::RuleModule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(26);
    left();
    setState(27);
    middle();
    setState(28);
    right();
    setState(29);
    match(StrParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void StrParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  strparserParserInitialize();
#else
  ::antlr4::internal::call_once(strparserParserOnceFlag, strparserParserInitialize);
#endif
}
