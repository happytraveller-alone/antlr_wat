
// Generated from StrLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  StrLexer : public antlr4::Lexer {
public:
  enum {
    KEY = 1, DIGIT = 2, LETTER = 3, LPAR = 4, RPAR = 5, LBRACE = 6, RBRACE = 7
  };

  explicit StrLexer(antlr4::CharStream *input);

  ~StrLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

