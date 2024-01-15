
// Generated from ECMAScript.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ECMAScriptParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ECMAScriptParser.
 */
class  ECMAScriptVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ECMAScriptParser.
   */
    virtual std::any visitProgram(ECMAScriptParser::ProgramContext *context) = 0;

    virtual std::any visitSourceElements(ECMAScriptParser::SourceElementsContext *context) = 0;

    virtual std::any visitSourceElement(ECMAScriptParser::SourceElementContext *context) = 0;

    virtual std::any visitStatement(ECMAScriptParser::StatementContext *context) = 0;

    virtual std::any visitBlock(ECMAScriptParser::BlockContext *context) = 0;

    virtual std::any visitStatementList(ECMAScriptParser::StatementListContext *context) = 0;

    virtual std::any visitVariableStatement(ECMAScriptParser::VariableStatementContext *context) = 0;

    virtual std::any visitVariableDeclarationList(ECMAScriptParser::VariableDeclarationListContext *context) = 0;

    virtual std::any visitVariableDeclaration(ECMAScriptParser::VariableDeclarationContext *context) = 0;

    virtual std::any visitInitialiser(ECMAScriptParser::InitialiserContext *context) = 0;

    virtual std::any visitEmptyStatement(ECMAScriptParser::EmptyStatementContext *context) = 0;

    virtual std::any visitExpressionStatement(ECMAScriptParser::ExpressionStatementContext *context) = 0;

    virtual std::any visitIfStatement(ECMAScriptParser::IfStatementContext *context) = 0;

    virtual std::any visitDoStatement(ECMAScriptParser::DoStatementContext *context) = 0;

    virtual std::any visitWhileStatement(ECMAScriptParser::WhileStatementContext *context) = 0;

    virtual std::any visitForStatement(ECMAScriptParser::ForStatementContext *context) = 0;

    virtual std::any visitForVarStatement(ECMAScriptParser::ForVarStatementContext *context) = 0;

    virtual std::any visitForLetStatement(ECMAScriptParser::ForLetStatementContext *context) = 0;

    virtual std::any visitForInStatement(ECMAScriptParser::ForInStatementContext *context) = 0;

    virtual std::any visitForVarInStatement(ECMAScriptParser::ForVarInStatementContext *context) = 0;

    virtual std::any visitForLetInStatement(ECMAScriptParser::ForLetInStatementContext *context) = 0;

    virtual std::any visitContinueStatement(ECMAScriptParser::ContinueStatementContext *context) = 0;

    virtual std::any visitBreakStatement(ECMAScriptParser::BreakStatementContext *context) = 0;

    virtual std::any visitReturnStatement(ECMAScriptParser::ReturnStatementContext *context) = 0;

    virtual std::any visitWithStatement(ECMAScriptParser::WithStatementContext *context) = 0;

    virtual std::any visitSwitchStatement(ECMAScriptParser::SwitchStatementContext *context) = 0;

    virtual std::any visitCaseBlock(ECMAScriptParser::CaseBlockContext *context) = 0;

    virtual std::any visitCaseClauses(ECMAScriptParser::CaseClausesContext *context) = 0;

    virtual std::any visitCaseClause(ECMAScriptParser::CaseClauseContext *context) = 0;

    virtual std::any visitDefaultClause(ECMAScriptParser::DefaultClauseContext *context) = 0;

    virtual std::any visitLabelledStatement(ECMAScriptParser::LabelledStatementContext *context) = 0;

    virtual std::any visitThrowStatement(ECMAScriptParser::ThrowStatementContext *context) = 0;

    virtual std::any visitTryStatement(ECMAScriptParser::TryStatementContext *context) = 0;

    virtual std::any visitCatchProduction(ECMAScriptParser::CatchProductionContext *context) = 0;

    virtual std::any visitFinallyProduction(ECMAScriptParser::FinallyProductionContext *context) = 0;

    virtual std::any visitDebuggerStatement(ECMAScriptParser::DebuggerStatementContext *context) = 0;

    virtual std::any visitFunctionDeclaration(ECMAScriptParser::FunctionDeclarationContext *context) = 0;

    virtual std::any visitFormalParameterList(ECMAScriptParser::FormalParameterListContext *context) = 0;

    virtual std::any visitFunctionBody(ECMAScriptParser::FunctionBodyContext *context) = 0;

    virtual std::any visitArrayLiteral(ECMAScriptParser::ArrayLiteralContext *context) = 0;

    virtual std::any visitElementList(ECMAScriptParser::ElementListContext *context) = 0;

    virtual std::any visitElision(ECMAScriptParser::ElisionContext *context) = 0;

    virtual std::any visitObjectLiteral(ECMAScriptParser::ObjectLiteralContext *context) = 0;

    virtual std::any visitPropertyNameAndValueList(ECMAScriptParser::PropertyNameAndValueListContext *context) = 0;

    virtual std::any visitPropertyExpressionAssignment(ECMAScriptParser::PropertyExpressionAssignmentContext *context) = 0;

    virtual std::any visitPropertyGetter(ECMAScriptParser::PropertyGetterContext *context) = 0;

    virtual std::any visitPropertySetter(ECMAScriptParser::PropertySetterContext *context) = 0;

    virtual std::any visitPropertyName(ECMAScriptParser::PropertyNameContext *context) = 0;

    virtual std::any visitPropertySetParameterList(ECMAScriptParser::PropertySetParameterListContext *context) = 0;

    virtual std::any visitArguments(ECMAScriptParser::ArgumentsContext *context) = 0;

    virtual std::any visitArgumentList(ECMAScriptParser::ArgumentListContext *context) = 0;

    virtual std::any visitExpressionSequence(ECMAScriptParser::ExpressionSequenceContext *context) = 0;

    virtual std::any visitTernaryExpression(ECMAScriptParser::TernaryExpressionContext *context) = 0;

    virtual std::any visitLogicalAndExpression(ECMAScriptParser::LogicalAndExpressionContext *context) = 0;

    virtual std::any visitPreIncrementExpression(ECMAScriptParser::PreIncrementExpressionContext *context) = 0;

    virtual std::any visitObjectLiteralExpression(ECMAScriptParser::ObjectLiteralExpressionContext *context) = 0;

    virtual std::any visitInExpression(ECMAScriptParser::InExpressionContext *context) = 0;

    virtual std::any visitLogicalOrExpression(ECMAScriptParser::LogicalOrExpressionContext *context) = 0;

    virtual std::any visitNotExpression(ECMAScriptParser::NotExpressionContext *context) = 0;

    virtual std::any visitPreDecreaseExpression(ECMAScriptParser::PreDecreaseExpressionContext *context) = 0;

    virtual std::any visitArgumentsExpression(ECMAScriptParser::ArgumentsExpressionContext *context) = 0;

    virtual std::any visitThisExpression(ECMAScriptParser::ThisExpressionContext *context) = 0;

    virtual std::any visitFunctionExpression(ECMAScriptParser::FunctionExpressionContext *context) = 0;

    virtual std::any visitUnaryMinusExpression(ECMAScriptParser::UnaryMinusExpressionContext *context) = 0;

    virtual std::any visitAssignmentExpression(ECMAScriptParser::AssignmentExpressionContext *context) = 0;

    virtual std::any visitPostDecreaseExpression(ECMAScriptParser::PostDecreaseExpressionContext *context) = 0;

    virtual std::any visitTypeofExpression(ECMAScriptParser::TypeofExpressionContext *context) = 0;

    virtual std::any visitInstanceofExpression(ECMAScriptParser::InstanceofExpressionContext *context) = 0;

    virtual std::any visitUnaryPlusExpression(ECMAScriptParser::UnaryPlusExpressionContext *context) = 0;

    virtual std::any visitDeleteExpression(ECMAScriptParser::DeleteExpressionContext *context) = 0;

    virtual std::any visitEqualityExpression(ECMAScriptParser::EqualityExpressionContext *context) = 0;

    virtual std::any visitBitXOrExpression(ECMAScriptParser::BitXOrExpressionContext *context) = 0;

    virtual std::any visitMultiplicativeExpression(ECMAScriptParser::MultiplicativeExpressionContext *context) = 0;

    virtual std::any visitBitShiftExpression(ECMAScriptParser::BitShiftExpressionContext *context) = 0;

    virtual std::any visitParenthesizedExpression(ECMAScriptParser::ParenthesizedExpressionContext *context) = 0;

    virtual std::any visitAdditiveExpression(ECMAScriptParser::AdditiveExpressionContext *context) = 0;

    virtual std::any visitRelationalExpression(ECMAScriptParser::RelationalExpressionContext *context) = 0;

    virtual std::any visitPostIncrementExpression(ECMAScriptParser::PostIncrementExpressionContext *context) = 0;

    virtual std::any visitBitNotExpression(ECMAScriptParser::BitNotExpressionContext *context) = 0;

    virtual std::any visitNewExpression(ECMAScriptParser::NewExpressionContext *context) = 0;

    virtual std::any visitLiteralExpression(ECMAScriptParser::LiteralExpressionContext *context) = 0;

    virtual std::any visitArrayLiteralExpression(ECMAScriptParser::ArrayLiteralExpressionContext *context) = 0;

    virtual std::any visitMemberDotExpression(ECMAScriptParser::MemberDotExpressionContext *context) = 0;

    virtual std::any visitMemberIndexExpression(ECMAScriptParser::MemberIndexExpressionContext *context) = 0;

    virtual std::any visitIdentifierExpression(ECMAScriptParser::IdentifierExpressionContext *context) = 0;

    virtual std::any visitBitAndExpression(ECMAScriptParser::BitAndExpressionContext *context) = 0;

    virtual std::any visitBitOrExpression(ECMAScriptParser::BitOrExpressionContext *context) = 0;

    virtual std::any visitAssignmentOperatorExpression(ECMAScriptParser::AssignmentOperatorExpressionContext *context) = 0;

    virtual std::any visitVoidExpression(ECMAScriptParser::VoidExpressionContext *context) = 0;

    virtual std::any visitAssignmentOperator(ECMAScriptParser::AssignmentOperatorContext *context) = 0;

    virtual std::any visitLiteral(ECMAScriptParser::LiteralContext *context) = 0;

    virtual std::any visitNumericLiteral(ECMAScriptParser::NumericLiteralContext *context) = 0;

    virtual std::any visitIdentifierName(ECMAScriptParser::IdentifierNameContext *context) = 0;

    virtual std::any visitReservedWord(ECMAScriptParser::ReservedWordContext *context) = 0;

    virtual std::any visitKeyword(ECMAScriptParser::KeywordContext *context) = 0;

    virtual std::any visitFutureReservedWord(ECMAScriptParser::FutureReservedWordContext *context) = 0;

    virtual std::any visitGetter(ECMAScriptParser::GetterContext *context) = 0;

    virtual std::any visitSetter(ECMAScriptParser::SetterContext *context) = 0;

    virtual std::any visitEos(ECMAScriptParser::EosContext *context) = 0;

    virtual std::any visitEof(ECMAScriptParser::EofContext *context) = 0;


};

