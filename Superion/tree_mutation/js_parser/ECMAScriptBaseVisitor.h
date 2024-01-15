
// Generated from ECMAScript.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ECMAScriptVisitor.h"


/**
 * This class provides an empty implementation of ECMAScriptVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ECMAScriptBaseVisitor : public ECMAScriptVisitor {
public:

  virtual std::any visitProgram(ECMAScriptParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSourceElements(ECMAScriptParser::SourceElementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSourceElement(ECMAScriptParser::SourceElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(ECMAScriptParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(ECMAScriptParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatementList(ECMAScriptParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableStatement(ECMAScriptParser::VariableStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclarationList(ECMAScriptParser::VariableDeclarationListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVariableDeclaration(ECMAScriptParser::VariableDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitialiser(ECMAScriptParser::InitialiserContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmptyStatement(ECMAScriptParser::EmptyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionStatement(ECMAScriptParser::ExpressionStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStatement(ECMAScriptParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoStatement(ECMAScriptParser::DoStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStatement(ECMAScriptParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStatement(ECMAScriptParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForVarStatement(ECMAScriptParser::ForVarStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForLetStatement(ECMAScriptParser::ForLetStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForInStatement(ECMAScriptParser::ForInStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForVarInStatement(ECMAScriptParser::ForVarInStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForLetInStatement(ECMAScriptParser::ForLetInStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueStatement(ECMAScriptParser::ContinueStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakStatement(ECMAScriptParser::BreakStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStatement(ECMAScriptParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithStatement(ECMAScriptParser::WithStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSwitchStatement(ECMAScriptParser::SwitchStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseBlock(ECMAScriptParser::CaseBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseClauses(ECMAScriptParser::CaseClausesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseClause(ECMAScriptParser::CaseClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefaultClause(ECMAScriptParser::DefaultClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLabelledStatement(ECMAScriptParser::LabelledStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThrowStatement(ECMAScriptParser::ThrowStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTryStatement(ECMAScriptParser::TryStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCatchProduction(ECMAScriptParser::CatchProductionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFinallyProduction(ECMAScriptParser::FinallyProductionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDebuggerStatement(ECMAScriptParser::DebuggerStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDeclaration(ECMAScriptParser::FunctionDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFormalParameterList(ECMAScriptParser::FormalParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionBody(ECMAScriptParser::FunctionBodyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayLiteral(ECMAScriptParser::ArrayLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElementList(ECMAScriptParser::ElementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElision(ECMAScriptParser::ElisionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObjectLiteral(ECMAScriptParser::ObjectLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyNameAndValueList(ECMAScriptParser::PropertyNameAndValueListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyExpressionAssignment(ECMAScriptParser::PropertyExpressionAssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyGetter(ECMAScriptParser::PropertyGetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertySetter(ECMAScriptParser::PropertySetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertyName(ECMAScriptParser::PropertyNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPropertySetParameterList(ECMAScriptParser::PropertySetParameterListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArguments(ECMAScriptParser::ArgumentsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentList(ECMAScriptParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpressionSequence(ECMAScriptParser::ExpressionSequenceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTernaryExpression(ECMAScriptParser::TernaryExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalAndExpression(ECMAScriptParser::LogicalAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPreIncrementExpression(ECMAScriptParser::PreIncrementExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitObjectLiteralExpression(ECMAScriptParser::ObjectLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInExpression(ECMAScriptParser::InExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLogicalOrExpression(ECMAScriptParser::LogicalOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpression(ECMAScriptParser::NotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPreDecreaseExpression(ECMAScriptParser::PreDecreaseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArgumentsExpression(ECMAScriptParser::ArgumentsExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThisExpression(ECMAScriptParser::ThisExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionExpression(ECMAScriptParser::FunctionExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryMinusExpression(ECMAScriptParser::UnaryMinusExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentExpression(ECMAScriptParser::AssignmentExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPostDecreaseExpression(ECMAScriptParser::PostDecreaseExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeofExpression(ECMAScriptParser::TypeofExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInstanceofExpression(ECMAScriptParser::InstanceofExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryPlusExpression(ECMAScriptParser::UnaryPlusExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeleteExpression(ECMAScriptParser::DeleteExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualityExpression(ECMAScriptParser::EqualityExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitXOrExpression(ECMAScriptParser::BitXOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultiplicativeExpression(ECMAScriptParser::MultiplicativeExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitShiftExpression(ECMAScriptParser::BitShiftExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParenthesizedExpression(ECMAScriptParser::ParenthesizedExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAdditiveExpression(ECMAScriptParser::AdditiveExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationalExpression(ECMAScriptParser::RelationalExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPostIncrementExpression(ECMAScriptParser::PostIncrementExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitNotExpression(ECMAScriptParser::BitNotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpression(ECMAScriptParser::NewExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteralExpression(ECMAScriptParser::LiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayLiteralExpression(ECMAScriptParser::ArrayLiteralExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberDotExpression(ECMAScriptParser::MemberDotExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberIndexExpression(ECMAScriptParser::MemberIndexExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierExpression(ECMAScriptParser::IdentifierExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitAndExpression(ECMAScriptParser::BitAndExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBitOrExpression(ECMAScriptParser::BitOrExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentOperatorExpression(ECMAScriptParser::AssignmentOperatorExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVoidExpression(ECMAScriptParser::VoidExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignmentOperator(ECMAScriptParser::AssignmentOperatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteral(ECMAScriptParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumericLiteral(ECMAScriptParser::NumericLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdentifierName(ECMAScriptParser::IdentifierNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReservedWord(ECMAScriptParser::ReservedWordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyword(ECMAScriptParser::KeywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFutureReservedWord(ECMAScriptParser::FutureReservedWordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGetter(ECMAScriptParser::GetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSetter(ECMAScriptParser::SetterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEos(ECMAScriptParser::EosContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEof(ECMAScriptParser::EofContext *ctx) override {
    return visitChildren(ctx);
  }


};

