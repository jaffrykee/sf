#pragma once

#using <mscorlib.dll>
#using <System.dll>
#using <System.Data.dll>
#using <System.Xml.dll>

using namespace System::Security::Permissions;
[assembly:SecurityPermissionAttribute(SecurityAction::RequestMinimum, SkipVerification=false)];
// 
// 此源代码由 xsd 自动生成, Version=4.0.30319.33440。
// 
using namespace System;
ref class dataFrame;


/// <summary>
///Represents a strongly typed in-memory cache of data.
///</summary>
[System::Serializable, 
System::ComponentModel::DesignerCategoryAttribute(L"code"), 
System::ComponentModel::ToolboxItem(true), 
System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedDataSetSchema"), 
System::Xml::Serialization::XmlRootAttribute(L"dataFrame"), 
System::ComponentModel::Design::HelpKeywordAttribute(L"vs.data.DataSet")]
public ref class dataFrame : public ::System::Data::DataSet {
    public : ref class imgFramesDataTable;
    public : ref class imgFrameDataTable;
    public : ref class SkillsDataTable;
    public : ref class SkillDataTable;
    public : ref class PlayersDataTable;
    public : ref class PlayerDataTable;
    public : ref class imgFramesRow;
    public : ref class imgFrameRow;
    public : ref class SkillsRow;
    public : ref class SkillRow;
    public : ref class PlayersRow;
    public : ref class PlayerRow;
    public : ref class imgFramesRowChangeEvent;
    public : ref class imgFrameRowChangeEvent;
    public : ref class SkillsRowChangeEvent;
    public : ref class SkillRowChangeEvent;
    public : ref class PlayersRowChangeEvent;
    public : ref class PlayerRowChangeEvent;
    
    private: dataFrame::imgFramesDataTable^  tableimgFrames;
    
    private: dataFrame::imgFrameDataTable^  tableimgFrame;
    
    private: dataFrame::SkillsDataTable^  tableSkills;
    
    private: dataFrame::SkillDataTable^  tableSkill;
    
    private: dataFrame::PlayersDataTable^  tablePlayers;
    
    private: dataFrame::PlayerDataTable^  tablePlayer;
    
    private: ::System::Data::DataRelation^  relationSkill_imgFrames;
    
    private: ::System::Data::DataRelation^  relationimgFrames_imgFrame;
    
    private: ::System::Data::DataRelation^  relationPlayer_Skills;
    
    private: ::System::Data::DataRelation^  relationSkills_Skill;
    
    private: ::System::Data::DataRelation^  relationPlayers_Player;
    
    private: ::System::Data::SchemaSerializationMode _schemaSerializationMode;
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void imgFramesRowChangeEventHandler(::System::Object^  sender, dataFrame::imgFramesRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void imgFrameRowChangeEventHandler(::System::Object^  sender, dataFrame::imgFrameRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void SkillsRowChangeEventHandler(::System::Object^  sender, dataFrame::SkillsRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void SkillRowChangeEventHandler(::System::Object^  sender, dataFrame::SkillRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void PlayersRowChangeEventHandler(::System::Object^  sender, dataFrame::PlayersRowChangeEvent^  e);
    
    public : [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    delegate System::Void PlayerRowChangeEventHandler(::System::Object^  sender, dataFrame::PlayerRowChangeEvent^  e);
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    dataFrame();
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    dataFrame(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property dataFrame::imgFramesDataTable^  imgFrames {
        dataFrame::imgFramesDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property dataFrame::imgFrameDataTable^  imgFrame {
        dataFrame::imgFrameDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property dataFrame::SkillsDataTable^  Skills {
        dataFrame::SkillsDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property dataFrame::SkillDataTable^  Skill {
        dataFrame::SkillDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property dataFrame::PlayersDataTable^  Players {
        dataFrame::PlayersDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::Browsable(false), 
    System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
    property dataFrame::PlayerDataTable^  Player {
        dataFrame::PlayerDataTable^  get();
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::BrowsableAttribute(true), 
    System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Visible)]
    virtual property ::System::Data::SchemaSerializationMode SchemaSerializationMode {
        ::System::Data::SchemaSerializationMode get() override;
        System::Void set(::System::Data::SchemaSerializationMode value) override;
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Hidden)]
    property ::System::Data::DataTableCollection^  Tables {
        ::System::Data::DataTableCollection^  get() new;
    }
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
    System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
    System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Hidden)]
    property ::System::Data::DataRelationCollection^  Relations {
        ::System::Data::DataRelationCollection^  get() new;
    }
    
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Void InitializeDerivedDataSet() override;
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Data::DataSet^  Clone() override;
    
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Boolean ShouldSerializeTables() override;
    
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Boolean ShouldSerializeRelations() override;
    
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Void ReadXmlSerializable(::System::Xml::XmlReader^  reader) override;
    
    protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    virtual ::System::Xml::Schema::XmlSchema^  GetSchemaSerializable() override;
    
    internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Void InitVars();
    
    internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Void InitVars(::System::Boolean initTable);
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Void InitClass();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeimgFrames();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeimgFrame();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeSkills();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializeSkill();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializePlayers();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Boolean ShouldSerializePlayer();
    
    private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ::System::Void SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e);
    
    public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class imgFramesDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnimgFrames_Id;
        
        private: ::System::Data::DataColumn^  columnSkill_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::imgFramesRowChangeEventHandler^  imgFramesRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::imgFramesRowChangeEventHandler^  imgFramesRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::imgFramesRowChangeEventHandler^  imgFramesRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::imgFramesRowChangeEventHandler^  imgFramesRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        imgFramesDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        imgFramesDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        imgFramesDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  imgFrames_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  Skill_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::imgFramesRow^  default [::System::Int32 ] {
            dataFrame::imgFramesRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddimgFramesRow(dataFrame::imgFramesRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::imgFramesRow^  AddimgFramesRow(dataFrame::SkillRow^  parentSkillRowBySkill_imgFrames);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::imgFramesRow^  NewimgFramesRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemoveimgFramesRow(dataFrame::imgFramesRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class imgFrameDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnid;
        
        private: ::System::Data::DataColumn^  columnimgX;
        
        private: ::System::Data::DataColumn^  columnimgY;
        
        private: ::System::Data::DataColumn^  columnimgPath;
        
        private: ::System::Data::DataColumn^  columnenAtted;
        
        private: ::System::Data::DataColumn^  columnselfX1;
        
        private: ::System::Data::DataColumn^  columnselfY1;
        
        private: ::System::Data::DataColumn^  columnselfX2;
        
        private: ::System::Data::DataColumn^  columnselfY2;
        
        private: ::System::Data::DataColumn^  columnenAtt;
        
        private: ::System::Data::DataColumn^  columnattX1;
        
        private: ::System::Data::DataColumn^  columnattY1;
        
        private: ::System::Data::DataColumn^  columnattX2;
        
        private: ::System::Data::DataColumn^  columnattY2;
        
        private: ::System::Data::DataColumn^  columnenBreak;
        
        private: ::System::Data::DataColumn^  columnenChain;
        
        private: ::System::Data::DataColumn^  columnchain1;
        
        private: ::System::Data::DataColumn^  columnchain2;
        
        private: ::System::Data::DataColumn^  columntime;
        
        private: ::System::Data::DataColumn^  columnimgFrames_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::imgFrameRowChangeEventHandler^  imgFrameRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::imgFrameRowChangeEventHandler^  imgFrameRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::imgFrameRowChangeEventHandler^  imgFrameRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::imgFrameRowChangeEventHandler^  imgFrameRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        imgFrameDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        imgFrameDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        imgFrameDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  idColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  imgXColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  imgYColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  imgPathColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  enAttedColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  selfX1Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  selfY1Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  selfX2Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  selfY2Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  enAttColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  attX1Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  attY1Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  attX2Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  attY2Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  enBreakColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  enChainColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  chain1Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  chain2Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  timeColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  imgFrames_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::imgFrameRow^  default [::System::Int32 ] {
            dataFrame::imgFrameRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddimgFrameRow(dataFrame::imgFrameRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::imgFrameRow^  AddimgFrameRow(
                    System::Int32 id, 
                    System::Single imgX, 
                    System::Single imgY, 
                    System::String^  imgPath, 
                    System::Boolean enAtted, 
                    System::Single selfX1, 
                    System::Single selfY1, 
                    System::Single selfX2, 
                    System::Single selfY2, 
                    System::Boolean enAtt, 
                    System::Single attX1, 
                    System::Single attY1, 
                    System::Single attX2, 
                    System::Single attY2, 
                    System::Boolean enBreak, 
                    System::Boolean enChain, 
                    System::Int32 chain1, 
                    System::Int32 chain2, 
                    System::Int32 time, 
                    dataFrame::imgFramesRow^  parentimgFramesRowByimgFrames_imgFrame);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::imgFrameRow^  NewimgFrameRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemoveimgFrameRow(dataFrame::imgFrameRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class SkillsDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnSkills_Id;
        
        private: ::System::Data::DataColumn^  columnPlayer_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::SkillsRowChangeEventHandler^  SkillsRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::SkillsRowChangeEventHandler^  SkillsRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::SkillsRowChangeEventHandler^  SkillsRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::SkillsRowChangeEventHandler^  SkillsRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        SkillsDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        SkillsDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        SkillsDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  Skills_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  Player_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::SkillsRow^  default [::System::Int32 ] {
            dataFrame::SkillsRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddSkillsRow(dataFrame::SkillsRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::SkillsRow^  AddSkillsRow(dataFrame::PlayerRow^  parentPlayerRowByPlayer_Skills);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::SkillsRow^  NewSkillsRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemoveSkillsRow(dataFrame::SkillsRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class SkillDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnid;
        
        private: ::System::Data::DataColumn^  columnname;
        
        private: ::System::Data::DataColumn^  columnkey;
        
        private: ::System::Data::DataColumn^  columnSkill_Id;
        
        private: ::System::Data::DataColumn^  columnSkills_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::SkillRowChangeEventHandler^  SkillRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::SkillRowChangeEventHandler^  SkillRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::SkillRowChangeEventHandler^  SkillRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::SkillRowChangeEventHandler^  SkillRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        SkillDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        SkillDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        SkillDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  idColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  nameColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  keyColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  Skill_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  Skills_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::SkillRow^  default [::System::Int32 ] {
            dataFrame::SkillRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddSkillRow(dataFrame::SkillRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::SkillRow^  AddSkillRow(System::Int32 id, System::String^  name, System::String^  key, dataFrame::SkillsRow^  parentSkillsRowBySkills_Skill);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::SkillRow^  NewSkillRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemoveSkillRow(dataFrame::SkillRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class PlayersDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnPlayers_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::PlayersRowChangeEventHandler^  PlayersRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::PlayersRowChangeEventHandler^  PlayersRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::PlayersRowChangeEventHandler^  PlayersRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::PlayersRowChangeEventHandler^  PlayersRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        PlayersDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        PlayersDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        PlayersDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  Players_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::PlayersRow^  default [::System::Int32 ] {
            dataFrame::PlayersRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddPlayersRow(dataFrame::PlayersRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::PlayersRow^  AddPlayersRow();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::PlayersRow^  NewPlayersRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemovePlayersRow(dataFrame::PlayersRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
    [System::Serializable, 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
    ref class PlayerDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
        
        private: ::System::Data::DataColumn^  columnid;
        
        private: ::System::Data::DataColumn^  columnname;
        
        private: ::System::Data::DataColumn^  columnheadImgPath;
        
        private: ::System::Data::DataColumn^  columnimgX1;
        
        private: ::System::Data::DataColumn^  columnimgY1;
        
        private: ::System::Data::DataColumn^  columnimgX2;
        
        private: ::System::Data::DataColumn^  columnimgY2;
        
        private: ::System::Data::DataColumn^  columnPlayer_Id;
        
        private: ::System::Data::DataColumn^  columnPlayers_Id;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::PlayerRowChangeEventHandler^  PlayerRowChanging;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::PlayerRowChangeEventHandler^  PlayerRowChanged;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::PlayerRowChangeEventHandler^  PlayerRowDeleting;
        
        public: [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        event dataFrame::PlayerRowChangeEventHandler^  PlayerRowDeleted;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        PlayerDataTable();
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        PlayerDataTable(::System::Data::DataTable^  table);
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        PlayerDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  idColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  nameColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  headImgPathColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  imgX1Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  imgY1Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  imgX2Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  imgY2Column {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  Player_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataColumn^  Players_IdColumn {
            ::System::Data::DataColumn^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0"), 
        System::ComponentModel::Browsable(false)]
        property ::System::Int32 Count {
            ::System::Int32 get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::PlayerRow^  default [::System::Int32 ] {
            dataFrame::PlayerRow^  get(::System::Int32 index);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void AddPlayerRow(dataFrame::PlayerRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::PlayerRow^  AddPlayerRow(
                    System::Int32 id, 
                    System::String^  name, 
                    System::String^  headImgPath, 
                    System::Int32 imgX1, 
                    System::Int32 imgY1, 
                    System::Int32 imgX2, 
                    System::Int32 imgY2, 
                    dataFrame::PlayersRow^  parentPlayersRowByPlayers_Player);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Collections::IEnumerator^  GetEnumerator();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataTable^  CreateInstance() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitVars();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void InitClass();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        dataFrame::PlayerRow^  NewPlayerRow();
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Type^  GetRowType() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void RemovePlayerRow(dataFrame::PlayerRow^  row);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class imgFramesRow : public ::System::Data::DataRow {
        
        private: dataFrame::imgFramesDataTable^  tableimgFrames;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        imgFramesRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 imgFrames_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 Skill_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::SkillRow^  SkillRow {
            dataFrame::SkillRow^  get();
            System::Void set(dataFrame::SkillRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsSkill_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetSkill_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< dataFrame::imgFrameRow^  >^  GetimgFrameRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class imgFrameRow : public ::System::Data::DataRow {
        
        private: dataFrame::imgFrameDataTable^  tableimgFrame;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        imgFrameRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single imgX {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single imgY {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::String^  imgPath {
            System::String^  get();
            System::Void set(System::String^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Boolean enAtted {
            System::Boolean get();
            System::Void set(System::Boolean value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single selfX1 {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single selfY1 {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single selfX2 {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single selfY2 {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Boolean enAtt {
            System::Boolean get();
            System::Void set(System::Boolean value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single attX1 {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single attY1 {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single attX2 {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Single attY2 {
            System::Single get();
            System::Void set(System::Single value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Boolean enBreak {
            System::Boolean get();
            System::Void set(System::Boolean value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Boolean enChain {
            System::Boolean get();
            System::Void set(System::Boolean value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 chain1 {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 chain2 {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 time {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 imgFrames_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::imgFramesRow^  imgFramesRow {
            dataFrame::imgFramesRow^  get();
            System::Void set(dataFrame::imgFramesRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsimgFrames_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetimgFrames_IdNull();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class SkillsRow : public ::System::Data::DataRow {
        
        private: dataFrame::SkillsDataTable^  tableSkills;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        SkillsRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 Skills_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 Player_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::PlayerRow^  PlayerRow {
            dataFrame::PlayerRow^  get();
            System::Void set(dataFrame::PlayerRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsPlayer_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetPlayer_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< dataFrame::SkillRow^  >^  GetSkillRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class SkillRow : public ::System::Data::DataRow {
        
        private: dataFrame::SkillDataTable^  tableSkill;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        SkillRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::String^  name {
            System::String^  get();
            System::Void set(System::String^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::String^  key {
            System::String^  get();
            System::Void set(System::String^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 Skill_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 Skills_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::SkillsRow^  SkillsRow {
            dataFrame::SkillsRow^  get();
            System::Void set(dataFrame::SkillsRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsSkills_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetSkills_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< dataFrame::imgFramesRow^  >^  GetimgFramesRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class PlayersRow : public ::System::Data::DataRow {
        
        private: dataFrame::PlayersDataTable^  tablePlayers;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        PlayersRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 Players_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< dataFrame::PlayerRow^  >^  GetPlayerRows();
    };
    
    public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
    ref class PlayerRow : public ::System::Data::DataRow {
        
        private: dataFrame::PlayerDataTable^  tablePlayer;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        PlayerRow(::System::Data::DataRowBuilder^  rb);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::String^  name {
            System::String^  get();
            System::Void set(System::String^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::String^  headImgPath {
            System::String^  get();
            System::Void set(System::String^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 imgX1 {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 imgY1 {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 imgX2 {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 imgY2 {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 Player_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property System::Int32 Players_Id {
            System::Int32 get();
            System::Void set(System::Int32 value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::PlayersRow^  PlayersRow {
            dataFrame::PlayersRow^  get();
            System::Void set(dataFrame::PlayersRow^  value);
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Boolean IsPlayers_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        ::System::Void SetPlayers_IdNull();
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        cli::array< dataFrame::SkillsRow^  >^  GetSkillsRows();
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class imgFramesRowChangeEvent : public ::System::EventArgs {
        
        private: dataFrame::imgFramesRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        imgFramesRowChangeEvent(dataFrame::imgFramesRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::imgFramesRow^  Row {
            dataFrame::imgFramesRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class imgFrameRowChangeEvent : public ::System::EventArgs {
        
        private: dataFrame::imgFrameRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        imgFrameRowChangeEvent(dataFrame::imgFrameRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::imgFrameRow^  Row {
            dataFrame::imgFrameRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class SkillsRowChangeEvent : public ::System::EventArgs {
        
        private: dataFrame::SkillsRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        SkillsRowChangeEvent(dataFrame::SkillsRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::SkillsRow^  Row {
            dataFrame::SkillsRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class SkillRowChangeEvent : public ::System::EventArgs {
        
        private: dataFrame::SkillRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        SkillRowChangeEvent(dataFrame::SkillRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::SkillRow^  Row {
            dataFrame::SkillRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class PlayersRowChangeEvent : public ::System::EventArgs {
        
        private: dataFrame::PlayersRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        PlayersRowChangeEvent(dataFrame::PlayersRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::PlayersRow^  Row {
            dataFrame::PlayersRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
    
    public : /// <summary>
///Row event argument class
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
    ref class PlayerRowChangeEvent : public ::System::EventArgs {
        
        private: dataFrame::PlayerRow^  eventRow;
        
        private: ::System::Data::DataRowAction eventAction;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        PlayerRowChangeEvent(dataFrame::PlayerRow^  row, ::System::Data::DataRowAction action);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property dataFrame::PlayerRow^  Row {
            dataFrame::PlayerRow^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"4.0.0.0")]
        property ::System::Data::DataRowAction Action {
            ::System::Data::DataRowAction get();
        }
    };
};


inline dataFrame::dataFrame() {
    this->BeginInit();
    this->InitClass();
    ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &dataFrame::SchemaChanged);
    __super::Tables->CollectionChanged += schemaChangedHandler;
    __super::Relations->CollectionChanged += schemaChangedHandler;
    this->EndInit();
}

inline dataFrame::dataFrame(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataSet(info, context, false) {
    if (this->IsBinarySerialized(info, context) == true) {
        this->InitVars(false);
        ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler1 = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &dataFrame::SchemaChanged);
        this->Tables->CollectionChanged += schemaChangedHandler1;
        this->Relations->CollectionChanged += schemaChangedHandler1;
        return;
    }
    ::System::String^  strSchema = (cli::safe_cast<::System::String^  >(info->GetValue(L"XmlSchema", ::System::String::typeid)));
    if (this->DetermineSchemaSerializationMode(info, context) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
        ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
        ds->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
        if (ds->Tables[L"imgFrames"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::imgFramesDataTable(ds->Tables[L"imgFrames"])));
        }
        if (ds->Tables[L"imgFrame"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::imgFrameDataTable(ds->Tables[L"imgFrame"])));
        }
        if (ds->Tables[L"Skills"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::SkillsDataTable(ds->Tables[L"Skills"])));
        }
        if (ds->Tables[L"Skill"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::SkillDataTable(ds->Tables[L"Skill"])));
        }
        if (ds->Tables[L"Players"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::PlayersDataTable(ds->Tables[L"Players"])));
        }
        if (ds->Tables[L"Player"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::PlayerDataTable(ds->Tables[L"Player"])));
        }
        this->DataSetName = ds->DataSetName;
        this->Prefix = ds->Prefix;
        this->Namespace = ds->Namespace;
        this->Locale = ds->Locale;
        this->CaseSensitive = ds->CaseSensitive;
        this->EnforceConstraints = ds->EnforceConstraints;
        this->Merge(ds, false, ::System::Data::MissingSchemaAction::Add);
        this->InitVars();
    }
    else {
        this->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
    }
    this->GetSerializationData(info, context);
    ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &dataFrame::SchemaChanged);
    __super::Tables->CollectionChanged += schemaChangedHandler;
    this->Relations->CollectionChanged += schemaChangedHandler;
}

inline dataFrame::imgFramesDataTable^  dataFrame::imgFrames::get() {
    return this->tableimgFrames;
}

inline dataFrame::imgFrameDataTable^  dataFrame::imgFrame::get() {
    return this->tableimgFrame;
}

inline dataFrame::SkillsDataTable^  dataFrame::Skills::get() {
    return this->tableSkills;
}

inline dataFrame::SkillDataTable^  dataFrame::Skill::get() {
    return this->tableSkill;
}

inline dataFrame::PlayersDataTable^  dataFrame::Players::get() {
    return this->tablePlayers;
}

inline dataFrame::PlayerDataTable^  dataFrame::Player::get() {
    return this->tablePlayer;
}

inline ::System::Data::SchemaSerializationMode dataFrame::SchemaSerializationMode::get() {
    return this->_schemaSerializationMode;
}
inline System::Void dataFrame::SchemaSerializationMode::set(::System::Data::SchemaSerializationMode value) {
    this->_schemaSerializationMode = __identifier(value);
}

inline ::System::Data::DataTableCollection^  dataFrame::Tables::get() {
    return __super::Tables;
}

inline ::System::Data::DataRelationCollection^  dataFrame::Relations::get() {
    return __super::Relations;
}

inline ::System::Void dataFrame::InitializeDerivedDataSet() {
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline ::System::Data::DataSet^  dataFrame::Clone() {
    dataFrame^  cln = (cli::safe_cast<dataFrame^  >(__super::Clone()));
    cln->InitVars();
    cln->SchemaSerializationMode = this->SchemaSerializationMode;
    return cln;
}

inline ::System::Boolean dataFrame::ShouldSerializeTables() {
    return false;
}

inline ::System::Boolean dataFrame::ShouldSerializeRelations() {
    return false;
}

inline ::System::Void dataFrame::ReadXmlSerializable(::System::Xml::XmlReader^  reader) {
    if (this->DetermineSchemaSerializationMode(reader) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
        this->Reset();
        ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
        ds->ReadXml(reader);
        if (ds->Tables[L"imgFrames"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::imgFramesDataTable(ds->Tables[L"imgFrames"])));
        }
        if (ds->Tables[L"imgFrame"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::imgFrameDataTable(ds->Tables[L"imgFrame"])));
        }
        if (ds->Tables[L"Skills"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::SkillsDataTable(ds->Tables[L"Skills"])));
        }
        if (ds->Tables[L"Skill"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::SkillDataTable(ds->Tables[L"Skill"])));
        }
        if (ds->Tables[L"Players"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::PlayersDataTable(ds->Tables[L"Players"])));
        }
        if (ds->Tables[L"Player"] != nullptr) {
            __super::Tables->Add((gcnew dataFrame::PlayerDataTable(ds->Tables[L"Player"])));
        }
        this->DataSetName = ds->DataSetName;
        this->Prefix = ds->Prefix;
        this->Namespace = ds->Namespace;
        this->Locale = ds->Locale;
        this->CaseSensitive = ds->CaseSensitive;
        this->EnforceConstraints = ds->EnforceConstraints;
        this->Merge(ds, false, ::System::Data::MissingSchemaAction::Add);
        this->InitVars();
    }
    else {
        this->ReadXml(reader);
        this->InitVars();
    }
}

inline ::System::Xml::Schema::XmlSchema^  dataFrame::GetSchemaSerializable() {
    ::System::IO::MemoryStream^  stream = (gcnew ::System::IO::MemoryStream());
    this->WriteXmlSchema((gcnew ::System::Xml::XmlTextWriter(stream, nullptr)));
    stream->Position = 0;
    return ::System::Xml::Schema::XmlSchema::Read((gcnew ::System::Xml::XmlTextReader(stream)), nullptr);
}

inline ::System::Void dataFrame::InitVars() {
    this->InitVars(true);
}

inline ::System::Void dataFrame::InitVars(::System::Boolean initTable) {
    this->tableimgFrames = (cli::safe_cast<dataFrame::imgFramesDataTable^  >(__super::Tables[L"imgFrames"]));
    if (initTable == true) {
        if (this->tableimgFrames != nullptr) {
            this->tableimgFrames->InitVars();
        }
    }
    this->tableimgFrame = (cli::safe_cast<dataFrame::imgFrameDataTable^  >(__super::Tables[L"imgFrame"]));
    if (initTable == true) {
        if (this->tableimgFrame != nullptr) {
            this->tableimgFrame->InitVars();
        }
    }
    this->tableSkills = (cli::safe_cast<dataFrame::SkillsDataTable^  >(__super::Tables[L"Skills"]));
    if (initTable == true) {
        if (this->tableSkills != nullptr) {
            this->tableSkills->InitVars();
        }
    }
    this->tableSkill = (cli::safe_cast<dataFrame::SkillDataTable^  >(__super::Tables[L"Skill"]));
    if (initTable == true) {
        if (this->tableSkill != nullptr) {
            this->tableSkill->InitVars();
        }
    }
    this->tablePlayers = (cli::safe_cast<dataFrame::PlayersDataTable^  >(__super::Tables[L"Players"]));
    if (initTable == true) {
        if (this->tablePlayers != nullptr) {
            this->tablePlayers->InitVars();
        }
    }
    this->tablePlayer = (cli::safe_cast<dataFrame::PlayerDataTable^  >(__super::Tables[L"Player"]));
    if (initTable == true) {
        if (this->tablePlayer != nullptr) {
            this->tablePlayer->InitVars();
        }
    }
    this->relationSkill_imgFrames = this->Relations[L"Skill_imgFrames"];
    this->relationimgFrames_imgFrame = this->Relations[L"imgFrames_imgFrame"];
    this->relationPlayer_Skills = this->Relations[L"Player_Skills"];
    this->relationSkills_Skill = this->Relations[L"Skills_Skill"];
    this->relationPlayers_Player = this->Relations[L"Players_Player"];
}

inline ::System::Void dataFrame::InitClass() {
    this->DataSetName = L"dataFrame";
    this->Prefix = L"";
    this->Namespace = L"http://tkmgame.com/shark/dataFrame.xsd";
    this->Locale = (gcnew ::System::Globalization::CultureInfo(L""));
    this->EnforceConstraints = true;
    this->SchemaSerializationMode = ::System::Data::SchemaSerializationMode::IncludeSchema;
    this->tableimgFrames = (gcnew dataFrame::imgFramesDataTable());
    __super::Tables->Add(this->tableimgFrames);
    this->tableimgFrame = (gcnew dataFrame::imgFrameDataTable());
    __super::Tables->Add(this->tableimgFrame);
    this->tableSkills = (gcnew dataFrame::SkillsDataTable());
    __super::Tables->Add(this->tableSkills);
    this->tableSkill = (gcnew dataFrame::SkillDataTable());
    __super::Tables->Add(this->tableSkill);
    this->tablePlayers = (gcnew dataFrame::PlayersDataTable());
    __super::Tables->Add(this->tablePlayers);
    this->tablePlayer = (gcnew dataFrame::PlayerDataTable());
    __super::Tables->Add(this->tablePlayer);
    ::System::Data::ForeignKeyConstraint^  fkc;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"Skill_imgFrames", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableSkill->Skill_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableimgFrames->Skill_IdColumn}));
    this->tableimgFrames->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"imgFrames_imgFrame", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableimgFrames->imgFrames_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableimgFrame->imgFrames_IdColumn}));
    this->tableimgFrame->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"Player_Skills", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablePlayer->Player_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableSkills->Player_IdColumn}));
    this->tableSkills->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"Skills_Skill", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableSkills->Skills_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableSkill->Skills_IdColumn}));
    this->tableSkill->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"Players_Player", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablePlayers->Players_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablePlayer->Players_IdColumn}));
    this->tablePlayer->Constraints->Add(fkc);
    fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
    fkc->DeleteRule = ::System::Data::Rule::Cascade;
    fkc->UpdateRule = ::System::Data::Rule::Cascade;
    this->relationSkill_imgFrames = (gcnew ::System::Data::DataRelation(L"Skill_imgFrames", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableSkill->Skill_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableimgFrames->Skill_IdColumn}, false));
    this->relationSkill_imgFrames->Nested = true;
    this->Relations->Add(this->relationSkill_imgFrames);
    this->relationimgFrames_imgFrame = (gcnew ::System::Data::DataRelation(L"imgFrames_imgFrame", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableimgFrames->imgFrames_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableimgFrame->imgFrames_IdColumn}, false));
    this->relationimgFrames_imgFrame->Nested = true;
    this->Relations->Add(this->relationimgFrames_imgFrame);
    this->relationPlayer_Skills = (gcnew ::System::Data::DataRelation(L"Player_Skills", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablePlayer->Player_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableSkills->Player_IdColumn}, false));
    this->relationPlayer_Skills->Nested = true;
    this->Relations->Add(this->relationPlayer_Skills);
    this->relationSkills_Skill = (gcnew ::System::Data::DataRelation(L"Skills_Skill", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableSkills->Skills_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableSkill->Skills_IdColumn}, false));
    this->relationSkills_Skill->Nested = true;
    this->Relations->Add(this->relationSkills_Skill);
    this->relationPlayers_Player = (gcnew ::System::Data::DataRelation(L"Players_Player", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablePlayers->Players_IdColumn}, 
        gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablePlayer->Players_IdColumn}, false));
    this->relationPlayers_Player->Nested = true;
    this->Relations->Add(this->relationPlayers_Player);
}

inline ::System::Boolean dataFrame::ShouldSerializeimgFrames() {
    return false;
}

inline ::System::Boolean dataFrame::ShouldSerializeimgFrame() {
    return false;
}

inline ::System::Boolean dataFrame::ShouldSerializeSkills() {
    return false;
}

inline ::System::Boolean dataFrame::ShouldSerializeSkill() {
    return false;
}

inline ::System::Boolean dataFrame::ShouldSerializePlayers() {
    return false;
}

inline ::System::Boolean dataFrame::ShouldSerializePlayer() {
    return false;
}

inline ::System::Void dataFrame::SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e) {
    if (e->Action == ::System::ComponentModel::CollectionChangeAction::Remove) {
        this->InitVars();
    }
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  dataFrame::GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    dataFrame^  ds = (gcnew dataFrame());
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    ::System::Xml::Schema::XmlSchemaAny^  any = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any->Namespace = ds->Namespace;
    sequence->Items->Add(any);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline dataFrame::imgFramesDataTable::imgFramesDataTable() {
    this->TableName = L"imgFrames";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline dataFrame::imgFramesDataTable::imgFramesDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline dataFrame::imgFramesDataTable::imgFramesDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  dataFrame::imgFramesDataTable::imgFrames_IdColumn::get() {
    return this->columnimgFrames_Id;
}

inline ::System::Data::DataColumn^  dataFrame::imgFramesDataTable::Skill_IdColumn::get() {
    return this->columnSkill_Id;
}

inline ::System::Int32 dataFrame::imgFramesDataTable::Count::get() {
    return this->Rows->Count;
}

inline dataFrame::imgFramesRow^  dataFrame::imgFramesDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<dataFrame::imgFramesRow^  >(this->Rows[index]));
}

inline ::System::Void dataFrame::imgFramesDataTable::AddimgFramesRow(dataFrame::imgFramesRow^  row) {
    this->Rows->Add(row);
}

inline dataFrame::imgFramesRow^  dataFrame::imgFramesDataTable::AddimgFramesRow(dataFrame::SkillRow^  parentSkillRowBySkill_imgFrames) {
    dataFrame::imgFramesRow^  rowimgFramesRow = (cli::safe_cast<dataFrame::imgFramesRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentSkillRowBySkill_imgFrames != nullptr) {
        columnValuesArray[1] = parentSkillRowBySkill_imgFrames[3];
    }
    rowimgFramesRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowimgFramesRow);
    return rowimgFramesRow;
}

inline ::System::Collections::IEnumerator^  dataFrame::imgFramesDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  dataFrame::imgFramesDataTable::Clone() {
    dataFrame::imgFramesDataTable^  cln = (cli::safe_cast<dataFrame::imgFramesDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  dataFrame::imgFramesDataTable::CreateInstance() {
    return (gcnew dataFrame::imgFramesDataTable());
}

inline ::System::Void dataFrame::imgFramesDataTable::InitVars() {
    this->columnimgFrames_Id = __super::Columns[L"imgFrames_Id"];
    this->columnSkill_Id = __super::Columns[L"Skill_Id"];
}

inline ::System::Void dataFrame::imgFramesDataTable::InitClass() {
    this->columnimgFrames_Id = (gcnew ::System::Data::DataColumn(L"imgFrames_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnimgFrames_Id);
    this->columnSkill_Id = (gcnew ::System::Data::DataColumn(L"Skill_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnSkill_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnimgFrames_Id}, 
            true)));
    this->columnimgFrames_Id->AutoIncrement = true;
    this->columnimgFrames_Id->AllowDBNull = false;
    this->columnimgFrames_Id->Unique = true;
}

inline dataFrame::imgFramesRow^  dataFrame::imgFramesDataTable::NewimgFramesRow() {
    return (cli::safe_cast<dataFrame::imgFramesRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  dataFrame::imgFramesDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew dataFrame::imgFramesRow(builder));
}

inline ::System::Type^  dataFrame::imgFramesDataTable::GetRowType() {
    return dataFrame::imgFramesRow::typeid;
}

inline ::System::Void dataFrame::imgFramesDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->imgFramesRowChanged(this, (gcnew dataFrame::imgFramesRowChangeEvent((cli::safe_cast<dataFrame::imgFramesRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::imgFramesDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->imgFramesRowChanging(this, (gcnew dataFrame::imgFramesRowChangeEvent((cli::safe_cast<dataFrame::imgFramesRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::imgFramesDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->imgFramesRowDeleted(this, (gcnew dataFrame::imgFramesRowChangeEvent((cli::safe_cast<dataFrame::imgFramesRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::imgFramesDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->imgFramesRowDeleting(this, (gcnew dataFrame::imgFramesRowChangeEvent((cli::safe_cast<dataFrame::imgFramesRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::imgFramesDataTable::RemoveimgFramesRow(dataFrame::imgFramesRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  dataFrame::imgFramesDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    dataFrame^  ds = (gcnew dataFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"imgFramesDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline dataFrame::imgFrameDataTable::imgFrameDataTable() {
    this->TableName = L"imgFrame";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline dataFrame::imgFrameDataTable::imgFrameDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline dataFrame::imgFrameDataTable::imgFrameDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::idColumn::get() {
    return this->columnid;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::imgXColumn::get() {
    return this->columnimgX;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::imgYColumn::get() {
    return this->columnimgY;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::imgPathColumn::get() {
    return this->columnimgPath;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::enAttedColumn::get() {
    return this->columnenAtted;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::selfX1Column::get() {
    return this->columnselfX1;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::selfY1Column::get() {
    return this->columnselfY1;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::selfX2Column::get() {
    return this->columnselfX2;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::selfY2Column::get() {
    return this->columnselfY2;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::enAttColumn::get() {
    return this->columnenAtt;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::attX1Column::get() {
    return this->columnattX1;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::attY1Column::get() {
    return this->columnattY1;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::attX2Column::get() {
    return this->columnattX2;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::attY2Column::get() {
    return this->columnattY2;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::enBreakColumn::get() {
    return this->columnenBreak;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::enChainColumn::get() {
    return this->columnenChain;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::chain1Column::get() {
    return this->columnchain1;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::chain2Column::get() {
    return this->columnchain2;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::timeColumn::get() {
    return this->columntime;
}

inline ::System::Data::DataColumn^  dataFrame::imgFrameDataTable::imgFrames_IdColumn::get() {
    return this->columnimgFrames_Id;
}

inline ::System::Int32 dataFrame::imgFrameDataTable::Count::get() {
    return this->Rows->Count;
}

inline dataFrame::imgFrameRow^  dataFrame::imgFrameDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<dataFrame::imgFrameRow^  >(this->Rows[index]));
}

inline ::System::Void dataFrame::imgFrameDataTable::AddimgFrameRow(dataFrame::imgFrameRow^  row) {
    this->Rows->Add(row);
}

inline dataFrame::imgFrameRow^  dataFrame::imgFrameDataTable::AddimgFrameRow(
            System::Int32 id, 
            System::Single imgX, 
            System::Single imgY, 
            System::String^  imgPath, 
            System::Boolean enAtted, 
            System::Single selfX1, 
            System::Single selfY1, 
            System::Single selfX2, 
            System::Single selfY2, 
            System::Boolean enAtt, 
            System::Single attX1, 
            System::Single attY1, 
            System::Single attX2, 
            System::Single attY2, 
            System::Boolean enBreak, 
            System::Boolean enChain, 
            System::Int32 chain1, 
            System::Int32 chain2, 
            System::Int32 time, 
            dataFrame::imgFramesRow^  parentimgFramesRowByimgFrames_imgFrame) {
    dataFrame::imgFrameRow^  rowimgFrameRow = (cli::safe_cast<dataFrame::imgFrameRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(20) {id, imgX, imgY, imgPath, 
        enAtted, selfX1, selfY1, selfX2, selfY2, enAtt, attX1, attY1, attX2, attY2, enBreak, enChain, chain1, chain2, time, nullptr};
    if (parentimgFramesRowByimgFrames_imgFrame != nullptr) {
        columnValuesArray[19] = parentimgFramesRowByimgFrames_imgFrame[0];
    }
    rowimgFrameRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowimgFrameRow);
    return rowimgFrameRow;
}

inline ::System::Collections::IEnumerator^  dataFrame::imgFrameDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  dataFrame::imgFrameDataTable::Clone() {
    dataFrame::imgFrameDataTable^  cln = (cli::safe_cast<dataFrame::imgFrameDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  dataFrame::imgFrameDataTable::CreateInstance() {
    return (gcnew dataFrame::imgFrameDataTable());
}

inline ::System::Void dataFrame::imgFrameDataTable::InitVars() {
    this->columnid = __super::Columns[L"id"];
    this->columnimgX = __super::Columns[L"imgX"];
    this->columnimgY = __super::Columns[L"imgY"];
    this->columnimgPath = __super::Columns[L"imgPath"];
    this->columnenAtted = __super::Columns[L"enAtted"];
    this->columnselfX1 = __super::Columns[L"selfX1"];
    this->columnselfY1 = __super::Columns[L"selfY1"];
    this->columnselfX2 = __super::Columns[L"selfX2"];
    this->columnselfY2 = __super::Columns[L"selfY2"];
    this->columnenAtt = __super::Columns[L"enAtt"];
    this->columnattX1 = __super::Columns[L"attX1"];
    this->columnattY1 = __super::Columns[L"attY1"];
    this->columnattX2 = __super::Columns[L"attX2"];
    this->columnattY2 = __super::Columns[L"attY2"];
    this->columnenBreak = __super::Columns[L"enBreak"];
    this->columnenChain = __super::Columns[L"enChain"];
    this->columnchain1 = __super::Columns[L"chain1"];
    this->columnchain2 = __super::Columns[L"chain2"];
    this->columntime = __super::Columns[L"time"];
    this->columnimgFrames_Id = __super::Columns[L"imgFrames_Id"];
}

inline ::System::Void dataFrame::imgFrameDataTable::InitClass() {
    this->columnid = (gcnew ::System::Data::DataColumn(L"id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnid);
    this->columnimgX = (gcnew ::System::Data::DataColumn(L"imgX", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnimgX);
    this->columnimgY = (gcnew ::System::Data::DataColumn(L"imgY", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnimgY);
    this->columnimgPath = (gcnew ::System::Data::DataColumn(L"imgPath", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnimgPath);
    this->columnenAtted = (gcnew ::System::Data::DataColumn(L"enAtted", ::System::Boolean::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnenAtted);
    this->columnselfX1 = (gcnew ::System::Data::DataColumn(L"selfX1", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnselfX1);
    this->columnselfY1 = (gcnew ::System::Data::DataColumn(L"selfY1", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnselfY1);
    this->columnselfX2 = (gcnew ::System::Data::DataColumn(L"selfX2", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnselfX2);
    this->columnselfY2 = (gcnew ::System::Data::DataColumn(L"selfY2", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnselfY2);
    this->columnenAtt = (gcnew ::System::Data::DataColumn(L"enAtt", ::System::Boolean::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnenAtt);
    this->columnattX1 = (gcnew ::System::Data::DataColumn(L"attX1", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnattX1);
    this->columnattY1 = (gcnew ::System::Data::DataColumn(L"attY1", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnattY1);
    this->columnattX2 = (gcnew ::System::Data::DataColumn(L"attX2", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnattX2);
    this->columnattY2 = (gcnew ::System::Data::DataColumn(L"attY2", ::System::Single::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnattY2);
    this->columnenBreak = (gcnew ::System::Data::DataColumn(L"enBreak", ::System::Boolean::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnenBreak);
    this->columnenChain = (gcnew ::System::Data::DataColumn(L"enChain", ::System::Boolean::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnenChain);
    this->columnchain1 = (gcnew ::System::Data::DataColumn(L"chain1", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnchain1);
    this->columnchain2 = (gcnew ::System::Data::DataColumn(L"chain2", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnchain2);
    this->columntime = (gcnew ::System::Data::DataColumn(L"time", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columntime);
    this->columnimgFrames_Id = (gcnew ::System::Data::DataColumn(L"imgFrames_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnimgFrames_Id);
    this->columnid->AllowDBNull = false;
    this->columnimgX->AllowDBNull = false;
    this->columnimgY->AllowDBNull = false;
    this->columnimgPath->AllowDBNull = false;
    this->columnenAtted->AllowDBNull = false;
    this->columnselfX1->AllowDBNull = false;
    this->columnselfY1->AllowDBNull = false;
    this->columnselfX2->AllowDBNull = false;
    this->columnselfY2->AllowDBNull = false;
    this->columnenAtt->AllowDBNull = false;
    this->columnattX1->AllowDBNull = false;
    this->columnattY1->AllowDBNull = false;
    this->columnattX2->AllowDBNull = false;
    this->columnattY2->AllowDBNull = false;
    this->columnenBreak->AllowDBNull = false;
    this->columnenChain->AllowDBNull = false;
    this->columnchain1->AllowDBNull = false;
    this->columnchain2->AllowDBNull = false;
    this->columntime->AllowDBNull = false;
}

inline dataFrame::imgFrameRow^  dataFrame::imgFrameDataTable::NewimgFrameRow() {
    return (cli::safe_cast<dataFrame::imgFrameRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  dataFrame::imgFrameDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew dataFrame::imgFrameRow(builder));
}

inline ::System::Type^  dataFrame::imgFrameDataTable::GetRowType() {
    return dataFrame::imgFrameRow::typeid;
}

inline ::System::Void dataFrame::imgFrameDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->imgFrameRowChanged(this, (gcnew dataFrame::imgFrameRowChangeEvent((cli::safe_cast<dataFrame::imgFrameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::imgFrameDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->imgFrameRowChanging(this, (gcnew dataFrame::imgFrameRowChangeEvent((cli::safe_cast<dataFrame::imgFrameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::imgFrameDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->imgFrameRowDeleted(this, (gcnew dataFrame::imgFrameRowChangeEvent((cli::safe_cast<dataFrame::imgFrameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::imgFrameDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->imgFrameRowDeleting(this, (gcnew dataFrame::imgFrameRowChangeEvent((cli::safe_cast<dataFrame::imgFrameRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::imgFrameDataTable::RemoveimgFrameRow(dataFrame::imgFrameRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  dataFrame::imgFrameDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    dataFrame^  ds = (gcnew dataFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"imgFrameDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline dataFrame::SkillsDataTable::SkillsDataTable() {
    this->TableName = L"Skills";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline dataFrame::SkillsDataTable::SkillsDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline dataFrame::SkillsDataTable::SkillsDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  dataFrame::SkillsDataTable::Skills_IdColumn::get() {
    return this->columnSkills_Id;
}

inline ::System::Data::DataColumn^  dataFrame::SkillsDataTable::Player_IdColumn::get() {
    return this->columnPlayer_Id;
}

inline ::System::Int32 dataFrame::SkillsDataTable::Count::get() {
    return this->Rows->Count;
}

inline dataFrame::SkillsRow^  dataFrame::SkillsDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<dataFrame::SkillsRow^  >(this->Rows[index]));
}

inline ::System::Void dataFrame::SkillsDataTable::AddSkillsRow(dataFrame::SkillsRow^  row) {
    this->Rows->Add(row);
}

inline dataFrame::SkillsRow^  dataFrame::SkillsDataTable::AddSkillsRow(dataFrame::PlayerRow^  parentPlayerRowByPlayer_Skills) {
    dataFrame::SkillsRow^  rowSkillsRow = (cli::safe_cast<dataFrame::SkillsRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(2) {nullptr, nullptr};
    if (parentPlayerRowByPlayer_Skills != nullptr) {
        columnValuesArray[1] = parentPlayerRowByPlayer_Skills[7];
    }
    rowSkillsRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowSkillsRow);
    return rowSkillsRow;
}

inline ::System::Collections::IEnumerator^  dataFrame::SkillsDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  dataFrame::SkillsDataTable::Clone() {
    dataFrame::SkillsDataTable^  cln = (cli::safe_cast<dataFrame::SkillsDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  dataFrame::SkillsDataTable::CreateInstance() {
    return (gcnew dataFrame::SkillsDataTable());
}

inline ::System::Void dataFrame::SkillsDataTable::InitVars() {
    this->columnSkills_Id = __super::Columns[L"Skills_Id"];
    this->columnPlayer_Id = __super::Columns[L"Player_Id"];
}

inline ::System::Void dataFrame::SkillsDataTable::InitClass() {
    this->columnSkills_Id = (gcnew ::System::Data::DataColumn(L"Skills_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnSkills_Id);
    this->columnPlayer_Id = (gcnew ::System::Data::DataColumn(L"Player_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnPlayer_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnSkills_Id}, 
            true)));
    this->columnSkills_Id->AutoIncrement = true;
    this->columnSkills_Id->AllowDBNull = false;
    this->columnSkills_Id->Unique = true;
}

inline dataFrame::SkillsRow^  dataFrame::SkillsDataTable::NewSkillsRow() {
    return (cli::safe_cast<dataFrame::SkillsRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  dataFrame::SkillsDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew dataFrame::SkillsRow(builder));
}

inline ::System::Type^  dataFrame::SkillsDataTable::GetRowType() {
    return dataFrame::SkillsRow::typeid;
}

inline ::System::Void dataFrame::SkillsDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->SkillsRowChanged(this, (gcnew dataFrame::SkillsRowChangeEvent((cli::safe_cast<dataFrame::SkillsRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::SkillsDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->SkillsRowChanging(this, (gcnew dataFrame::SkillsRowChangeEvent((cli::safe_cast<dataFrame::SkillsRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::SkillsDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->SkillsRowDeleted(this, (gcnew dataFrame::SkillsRowChangeEvent((cli::safe_cast<dataFrame::SkillsRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::SkillsDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->SkillsRowDeleting(this, (gcnew dataFrame::SkillsRowChangeEvent((cli::safe_cast<dataFrame::SkillsRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::SkillsDataTable::RemoveSkillsRow(dataFrame::SkillsRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  dataFrame::SkillsDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    dataFrame^  ds = (gcnew dataFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"SkillsDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline dataFrame::SkillDataTable::SkillDataTable() {
    this->TableName = L"Skill";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline dataFrame::SkillDataTable::SkillDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline dataFrame::SkillDataTable::SkillDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  dataFrame::SkillDataTable::idColumn::get() {
    return this->columnid;
}

inline ::System::Data::DataColumn^  dataFrame::SkillDataTable::nameColumn::get() {
    return this->columnname;
}

inline ::System::Data::DataColumn^  dataFrame::SkillDataTable::keyColumn::get() {
    return this->columnkey;
}

inline ::System::Data::DataColumn^  dataFrame::SkillDataTable::Skill_IdColumn::get() {
    return this->columnSkill_Id;
}

inline ::System::Data::DataColumn^  dataFrame::SkillDataTable::Skills_IdColumn::get() {
    return this->columnSkills_Id;
}

inline ::System::Int32 dataFrame::SkillDataTable::Count::get() {
    return this->Rows->Count;
}

inline dataFrame::SkillRow^  dataFrame::SkillDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<dataFrame::SkillRow^  >(this->Rows[index]));
}

inline ::System::Void dataFrame::SkillDataTable::AddSkillRow(dataFrame::SkillRow^  row) {
    this->Rows->Add(row);
}

inline dataFrame::SkillRow^  dataFrame::SkillDataTable::AddSkillRow(System::Int32 id, System::String^  name, System::String^  key, 
            dataFrame::SkillsRow^  parentSkillsRowBySkills_Skill) {
    dataFrame::SkillRow^  rowSkillRow = (cli::safe_cast<dataFrame::SkillRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(5) {id, name, key, nullptr, 
        nullptr};
    if (parentSkillsRowBySkills_Skill != nullptr) {
        columnValuesArray[4] = parentSkillsRowBySkills_Skill[0];
    }
    rowSkillRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowSkillRow);
    return rowSkillRow;
}

inline ::System::Collections::IEnumerator^  dataFrame::SkillDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  dataFrame::SkillDataTable::Clone() {
    dataFrame::SkillDataTable^  cln = (cli::safe_cast<dataFrame::SkillDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  dataFrame::SkillDataTable::CreateInstance() {
    return (gcnew dataFrame::SkillDataTable());
}

inline ::System::Void dataFrame::SkillDataTable::InitVars() {
    this->columnid = __super::Columns[L"id"];
    this->columnname = __super::Columns[L"name"];
    this->columnkey = __super::Columns[L"key"];
    this->columnSkill_Id = __super::Columns[L"Skill_Id"];
    this->columnSkills_Id = __super::Columns[L"Skills_Id"];
}

inline ::System::Void dataFrame::SkillDataTable::InitClass() {
    this->columnid = (gcnew ::System::Data::DataColumn(L"id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnid);
    this->columnname = (gcnew ::System::Data::DataColumn(L"name", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnname);
    this->columnkey = (gcnew ::System::Data::DataColumn(L"key", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnkey);
    this->columnSkill_Id = (gcnew ::System::Data::DataColumn(L"Skill_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnSkill_Id);
    this->columnSkills_Id = (gcnew ::System::Data::DataColumn(L"Skills_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnSkills_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnSkill_Id}, 
            true)));
    this->columnid->AllowDBNull = false;
    this->columnname->AllowDBNull = false;
    this->columnkey->AllowDBNull = false;
    this->columnSkill_Id->AutoIncrement = true;
    this->columnSkill_Id->AllowDBNull = false;
    this->columnSkill_Id->Unique = true;
}

inline dataFrame::SkillRow^  dataFrame::SkillDataTable::NewSkillRow() {
    return (cli::safe_cast<dataFrame::SkillRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  dataFrame::SkillDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew dataFrame::SkillRow(builder));
}

inline ::System::Type^  dataFrame::SkillDataTable::GetRowType() {
    return dataFrame::SkillRow::typeid;
}

inline ::System::Void dataFrame::SkillDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->SkillRowChanged(this, (gcnew dataFrame::SkillRowChangeEvent((cli::safe_cast<dataFrame::SkillRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void dataFrame::SkillDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->SkillRowChanging(this, (gcnew dataFrame::SkillRowChangeEvent((cli::safe_cast<dataFrame::SkillRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::SkillDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->SkillRowDeleted(this, (gcnew dataFrame::SkillRowChangeEvent((cli::safe_cast<dataFrame::SkillRow^  >(e->Row)), e->Action)));
    }
}

inline ::System::Void dataFrame::SkillDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->SkillRowDeleting(this, (gcnew dataFrame::SkillRowChangeEvent((cli::safe_cast<dataFrame::SkillRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::SkillDataTable::RemoveSkillRow(dataFrame::SkillRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  dataFrame::SkillDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    dataFrame^  ds = (gcnew dataFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"SkillDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline dataFrame::PlayersDataTable::PlayersDataTable() {
    this->TableName = L"Players";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline dataFrame::PlayersDataTable::PlayersDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline dataFrame::PlayersDataTable::PlayersDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  dataFrame::PlayersDataTable::Players_IdColumn::get() {
    return this->columnPlayers_Id;
}

inline ::System::Int32 dataFrame::PlayersDataTable::Count::get() {
    return this->Rows->Count;
}

inline dataFrame::PlayersRow^  dataFrame::PlayersDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<dataFrame::PlayersRow^  >(this->Rows[index]));
}

inline ::System::Void dataFrame::PlayersDataTable::AddPlayersRow(dataFrame::PlayersRow^  row) {
    this->Rows->Add(row);
}

inline dataFrame::PlayersRow^  dataFrame::PlayersDataTable::AddPlayersRow() {
    dataFrame::PlayersRow^  rowPlayersRow = (cli::safe_cast<dataFrame::PlayersRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(1) {nullptr};
    rowPlayersRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowPlayersRow);
    return rowPlayersRow;
}

inline ::System::Collections::IEnumerator^  dataFrame::PlayersDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  dataFrame::PlayersDataTable::Clone() {
    dataFrame::PlayersDataTable^  cln = (cli::safe_cast<dataFrame::PlayersDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  dataFrame::PlayersDataTable::CreateInstance() {
    return (gcnew dataFrame::PlayersDataTable());
}

inline ::System::Void dataFrame::PlayersDataTable::InitVars() {
    this->columnPlayers_Id = __super::Columns[L"Players_Id"];
}

inline ::System::Void dataFrame::PlayersDataTable::InitClass() {
    this->columnPlayers_Id = (gcnew ::System::Data::DataColumn(L"Players_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnPlayers_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnPlayers_Id}, 
            true)));
    this->columnPlayers_Id->AutoIncrement = true;
    this->columnPlayers_Id->AllowDBNull = false;
    this->columnPlayers_Id->Unique = true;
}

inline dataFrame::PlayersRow^  dataFrame::PlayersDataTable::NewPlayersRow() {
    return (cli::safe_cast<dataFrame::PlayersRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  dataFrame::PlayersDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew dataFrame::PlayersRow(builder));
}

inline ::System::Type^  dataFrame::PlayersDataTable::GetRowType() {
    return dataFrame::PlayersRow::typeid;
}

inline ::System::Void dataFrame::PlayersDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->PlayersRowChanged(this, (gcnew dataFrame::PlayersRowChangeEvent((cli::safe_cast<dataFrame::PlayersRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::PlayersDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->PlayersRowChanging(this, (gcnew dataFrame::PlayersRowChangeEvent((cli::safe_cast<dataFrame::PlayersRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::PlayersDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->PlayersRowDeleted(this, (gcnew dataFrame::PlayersRowChangeEvent((cli::safe_cast<dataFrame::PlayersRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::PlayersDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->PlayersRowDeleting(this, (gcnew dataFrame::PlayersRowChangeEvent((cli::safe_cast<dataFrame::PlayersRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::PlayersDataTable::RemovePlayersRow(dataFrame::PlayersRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  dataFrame::PlayersDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    dataFrame^  ds = (gcnew dataFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"PlayersDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline dataFrame::PlayerDataTable::PlayerDataTable() {
    this->TableName = L"Player";
    this->BeginInit();
    this->InitClass();
    this->EndInit();
}

inline dataFrame::PlayerDataTable::PlayerDataTable(::System::Data::DataTable^  table) {
    this->TableName = table->TableName;
    if (table->CaseSensitive != table->DataSet->CaseSensitive) {
        this->CaseSensitive = table->CaseSensitive;
    }
    if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
        this->Locale = table->Locale;
    }
    if (table->Namespace != table->DataSet->Namespace) {
        this->Namespace = table->Namespace;
    }
    this->Prefix = table->Prefix;
    this->MinimumCapacity = table->MinimumCapacity;
}

inline dataFrame::PlayerDataTable::PlayerDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
        ::System::Data::DataTable(info, context) {
    this->InitVars();
}

inline ::System::Data::DataColumn^  dataFrame::PlayerDataTable::idColumn::get() {
    return this->columnid;
}

inline ::System::Data::DataColumn^  dataFrame::PlayerDataTable::nameColumn::get() {
    return this->columnname;
}

inline ::System::Data::DataColumn^  dataFrame::PlayerDataTable::headImgPathColumn::get() {
    return this->columnheadImgPath;
}

inline ::System::Data::DataColumn^  dataFrame::PlayerDataTable::imgX1Column::get() {
    return this->columnimgX1;
}

inline ::System::Data::DataColumn^  dataFrame::PlayerDataTable::imgY1Column::get() {
    return this->columnimgY1;
}

inline ::System::Data::DataColumn^  dataFrame::PlayerDataTable::imgX2Column::get() {
    return this->columnimgX2;
}

inline ::System::Data::DataColumn^  dataFrame::PlayerDataTable::imgY2Column::get() {
    return this->columnimgY2;
}

inline ::System::Data::DataColumn^  dataFrame::PlayerDataTable::Player_IdColumn::get() {
    return this->columnPlayer_Id;
}

inline ::System::Data::DataColumn^  dataFrame::PlayerDataTable::Players_IdColumn::get() {
    return this->columnPlayers_Id;
}

inline ::System::Int32 dataFrame::PlayerDataTable::Count::get() {
    return this->Rows->Count;
}

inline dataFrame::PlayerRow^  dataFrame::PlayerDataTable::default::get(::System::Int32 index) {
    return (cli::safe_cast<dataFrame::PlayerRow^  >(this->Rows[index]));
}

inline ::System::Void dataFrame::PlayerDataTable::AddPlayerRow(dataFrame::PlayerRow^  row) {
    this->Rows->Add(row);
}

inline dataFrame::PlayerRow^  dataFrame::PlayerDataTable::AddPlayerRow(
            System::Int32 id, 
            System::String^  name, 
            System::String^  headImgPath, 
            System::Int32 imgX1, 
            System::Int32 imgY1, 
            System::Int32 imgX2, 
            System::Int32 imgY2, 
            dataFrame::PlayersRow^  parentPlayersRowByPlayers_Player) {
    dataFrame::PlayerRow^  rowPlayerRow = (cli::safe_cast<dataFrame::PlayerRow^  >(this->NewRow()));
    cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(9) {id, name, headImgPath, 
        imgX1, imgY1, imgX2, imgY2, nullptr, nullptr};
    if (parentPlayersRowByPlayers_Player != nullptr) {
        columnValuesArray[8] = parentPlayersRowByPlayers_Player[0];
    }
    rowPlayerRow->ItemArray = columnValuesArray;
    this->Rows->Add(rowPlayerRow);
    return rowPlayerRow;
}

inline ::System::Collections::IEnumerator^  dataFrame::PlayerDataTable::GetEnumerator() {
    return this->Rows->GetEnumerator();
}

inline ::System::Data::DataTable^  dataFrame::PlayerDataTable::Clone() {
    dataFrame::PlayerDataTable^  cln = (cli::safe_cast<dataFrame::PlayerDataTable^  >(__super::Clone()));
    cln->InitVars();
    return cln;
}

inline ::System::Data::DataTable^  dataFrame::PlayerDataTable::CreateInstance() {
    return (gcnew dataFrame::PlayerDataTable());
}

inline ::System::Void dataFrame::PlayerDataTable::InitVars() {
    this->columnid = __super::Columns[L"id"];
    this->columnname = __super::Columns[L"name"];
    this->columnheadImgPath = __super::Columns[L"headImgPath"];
    this->columnimgX1 = __super::Columns[L"imgX1"];
    this->columnimgY1 = __super::Columns[L"imgY1"];
    this->columnimgX2 = __super::Columns[L"imgX2"];
    this->columnimgY2 = __super::Columns[L"imgY2"];
    this->columnPlayer_Id = __super::Columns[L"Player_Id"];
    this->columnPlayers_Id = __super::Columns[L"Players_Id"];
}

inline ::System::Void dataFrame::PlayerDataTable::InitClass() {
    this->columnid = (gcnew ::System::Data::DataColumn(L"id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnid);
    this->columnname = (gcnew ::System::Data::DataColumn(L"name", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnname);
    this->columnheadImgPath = (gcnew ::System::Data::DataColumn(L"headImgPath", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnheadImgPath);
    this->columnimgX1 = (gcnew ::System::Data::DataColumn(L"imgX1", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnimgX1);
    this->columnimgY1 = (gcnew ::System::Data::DataColumn(L"imgY1", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnimgY1);
    this->columnimgX2 = (gcnew ::System::Data::DataColumn(L"imgX2", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnimgX2);
    this->columnimgY2 = (gcnew ::System::Data::DataColumn(L"imgY2", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Element));
    __super::Columns->Add(this->columnimgY2);
    this->columnPlayer_Id = (gcnew ::System::Data::DataColumn(L"Player_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnPlayer_Id);
    this->columnPlayers_Id = (gcnew ::System::Data::DataColumn(L"Players_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
    __super::Columns->Add(this->columnPlayers_Id);
    this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columnPlayer_Id}, 
            true)));
    this->columnid->AllowDBNull = false;
    this->columnname->AllowDBNull = false;
    this->columnheadImgPath->AllowDBNull = false;
    this->columnimgX1->AllowDBNull = false;
    this->columnimgY1->AllowDBNull = false;
    this->columnimgX2->AllowDBNull = false;
    this->columnimgY2->AllowDBNull = false;
    this->columnPlayer_Id->AutoIncrement = true;
    this->columnPlayer_Id->AllowDBNull = false;
    this->columnPlayer_Id->Unique = true;
}

inline dataFrame::PlayerRow^  dataFrame::PlayerDataTable::NewPlayerRow() {
    return (cli::safe_cast<dataFrame::PlayerRow^  >(this->NewRow()));
}

inline ::System::Data::DataRow^  dataFrame::PlayerDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
    return (gcnew dataFrame::PlayerRow(builder));
}

inline ::System::Type^  dataFrame::PlayerDataTable::GetRowType() {
    return dataFrame::PlayerRow::typeid;
}

inline ::System::Void dataFrame::PlayerDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanged(e);
    {
        this->PlayerRowChanged(this, (gcnew dataFrame::PlayerRowChangeEvent((cli::safe_cast<dataFrame::PlayerRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::PlayerDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowChanging(e);
    {
        this->PlayerRowChanging(this, (gcnew dataFrame::PlayerRowChangeEvent((cli::safe_cast<dataFrame::PlayerRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::PlayerDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleted(e);
    {
        this->PlayerRowDeleted(this, (gcnew dataFrame::PlayerRowChangeEvent((cli::safe_cast<dataFrame::PlayerRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::PlayerDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
    __super::OnRowDeleting(e);
    {
        this->PlayerRowDeleting(this, (gcnew dataFrame::PlayerRowChangeEvent((cli::safe_cast<dataFrame::PlayerRow^  >(e->Row)), 
                e->Action)));
    }
}

inline ::System::Void dataFrame::PlayerDataTable::RemovePlayerRow(dataFrame::PlayerRow^  row) {
    this->Rows->Remove(row);
}

inline ::System::Xml::Schema::XmlSchemaComplexType^  dataFrame::PlayerDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
    ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
    ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
    dataFrame^  ds = (gcnew dataFrame());
    ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
    any1->MinOccurs = ::System::Decimal(0);
    any1->MaxOccurs = ::System::Decimal::MaxValue;
    any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any1);
    ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
    any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
    any2->MinOccurs = ::System::Decimal(1);
    any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
    sequence->Items->Add(any2);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute1->Name = L"namespace";
    attribute1->FixedValue = ds->Namespace;
    type->Attributes->Add(attribute1);
    ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
    attribute2->Name = L"tableTypeName";
    attribute2->FixedValue = L"PlayerDataTable";
    type->Attributes->Add(attribute2);
    type->Particle = sequence;
    ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
    if (xs->Contains(dsSchema->TargetNamespace)) {
        ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
        ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
        try {
            ::System::Xml::Schema::XmlSchema^  schema = nullptr;
            dsSchema->Write(s1);
            for (            ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();             ) {
                schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                s2->SetLength(0);
                schema->Write(s2);
                if (s1->Length == s2->Length) {
                    s1->Position = 0;
                    s2->Position = 0;
                    for (                    ; ((s1->Position != s1->Length) 
                                && (s1->ReadByte() == s2->ReadByte()));                     ) {
                        ;
                    }
                    if (s1->Position == s1->Length) {
                        return type;
                    }
                }
            }
        }
        finally {
            if (s1 != nullptr) {
                s1->Close();
            }
            if (s2 != nullptr) {
                s2->Close();
            }
        }
    }
    xs->Add(dsSchema);
    return type;
}


inline dataFrame::imgFramesRow::imgFramesRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableimgFrames = (cli::safe_cast<dataFrame::imgFramesDataTable^  >(this->Table));
}

inline System::Int32 dataFrame::imgFramesRow::imgFrames_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableimgFrames->imgFrames_IdColumn]));
}
inline System::Void dataFrame::imgFramesRow::imgFrames_Id::set(System::Int32 value) {
    this[this->tableimgFrames->imgFrames_IdColumn] = value;
}

inline System::Int32 dataFrame::imgFramesRow::Skill_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableimgFrames->Skill_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“imgFrames”中列“Skill_Id”的值为 DBNull。", e));
    }
}
inline System::Void dataFrame::imgFramesRow::Skill_Id::set(System::Int32 value) {
    this[this->tableimgFrames->Skill_IdColumn] = value;
}

inline dataFrame::SkillRow^  dataFrame::imgFramesRow::SkillRow::get() {
    return (cli::safe_cast<dataFrame::SkillRow^  >(this->GetParentRow(this->Table->ParentRelations[L"Skill_imgFrames"])));
}
inline System::Void dataFrame::imgFramesRow::SkillRow::set(dataFrame::SkillRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"Skill_imgFrames"]);
}

inline ::System::Boolean dataFrame::imgFramesRow::IsSkill_IdNull() {
    return this->IsNull(this->tableimgFrames->Skill_IdColumn);
}

inline ::System::Void dataFrame::imgFramesRow::SetSkill_IdNull() {
    this[this->tableimgFrames->Skill_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< dataFrame::imgFrameRow^  >^  dataFrame::imgFramesRow::GetimgFrameRows() {
    if (this->Table->ChildRelations[L"imgFrames_imgFrame"] == nullptr) {
        return gcnew cli::array< dataFrame::imgFrameRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< dataFrame::imgFrameRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"imgFrames_imgFrame"])));
    }
}


inline dataFrame::imgFrameRow::imgFrameRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableimgFrame = (cli::safe_cast<dataFrame::imgFrameDataTable^  >(this->Table));
}

inline System::Int32 dataFrame::imgFrameRow::id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableimgFrame->idColumn]));
}
inline System::Void dataFrame::imgFrameRow::id::set(System::Int32 value) {
    this[this->tableimgFrame->idColumn] = value;
}

inline System::Single dataFrame::imgFrameRow::imgX::get() {
    return (cli::safe_cast<::System::Single >(this[this->tableimgFrame->imgXColumn]));
}
inline System::Void dataFrame::imgFrameRow::imgX::set(System::Single value) {
    this[this->tableimgFrame->imgXColumn] = value;
}

inline System::Single dataFrame::imgFrameRow::imgY::get() {
    return (cli::safe_cast<::System::Single >(this[this->tableimgFrame->imgYColumn]));
}
inline System::Void dataFrame::imgFrameRow::imgY::set(System::Single value) {
    this[this->tableimgFrame->imgYColumn] = value;
}

inline System::String^  dataFrame::imgFrameRow::imgPath::get() {
    return (cli::safe_cast<::System::String^  >(this[this->tableimgFrame->imgPathColumn]));
}
inline System::Void dataFrame::imgFrameRow::imgPath::set(System::String^  value) {
    this[this->tableimgFrame->imgPathColumn] = value;
}

inline System::Boolean dataFrame::imgFrameRow::enAtted::get() {
    return (cli::safe_cast<::System::Boolean >(this[this->tableimgFrame->enAttedColumn]));
}
inline System::Void dataFrame::imgFrameRow::enAtted::set(System::Boolean value) {
    this[this->tableimgFrame->enAttedColumn] = value;
}

inline System::Single dataFrame::imgFrameRow::selfX1::get() {
    return (cli::safe_cast<::System::Single >(this[this->tableimgFrame->selfX1Column]));
}
inline System::Void dataFrame::imgFrameRow::selfX1::set(System::Single value) {
    this[this->tableimgFrame->selfX1Column] = value;
}

inline System::Single dataFrame::imgFrameRow::selfY1::get() {
    return (cli::safe_cast<::System::Single >(this[this->tableimgFrame->selfY1Column]));
}
inline System::Void dataFrame::imgFrameRow::selfY1::set(System::Single value) {
    this[this->tableimgFrame->selfY1Column] = value;
}

inline System::Single dataFrame::imgFrameRow::selfX2::get() {
    return (cli::safe_cast<::System::Single >(this[this->tableimgFrame->selfX2Column]));
}
inline System::Void dataFrame::imgFrameRow::selfX2::set(System::Single value) {
    this[this->tableimgFrame->selfX2Column] = value;
}

inline System::Single dataFrame::imgFrameRow::selfY2::get() {
    return (cli::safe_cast<::System::Single >(this[this->tableimgFrame->selfY2Column]));
}
inline System::Void dataFrame::imgFrameRow::selfY2::set(System::Single value) {
    this[this->tableimgFrame->selfY2Column] = value;
}

inline System::Boolean dataFrame::imgFrameRow::enAtt::get() {
    return (cli::safe_cast<::System::Boolean >(this[this->tableimgFrame->enAttColumn]));
}
inline System::Void dataFrame::imgFrameRow::enAtt::set(System::Boolean value) {
    this[this->tableimgFrame->enAttColumn] = value;
}

inline System::Single dataFrame::imgFrameRow::attX1::get() {
    return (cli::safe_cast<::System::Single >(this[this->tableimgFrame->attX1Column]));
}
inline System::Void dataFrame::imgFrameRow::attX1::set(System::Single value) {
    this[this->tableimgFrame->attX1Column] = value;
}

inline System::Single dataFrame::imgFrameRow::attY1::get() {
    return (cli::safe_cast<::System::Single >(this[this->tableimgFrame->attY1Column]));
}
inline System::Void dataFrame::imgFrameRow::attY1::set(System::Single value) {
    this[this->tableimgFrame->attY1Column] = value;
}

inline System::Single dataFrame::imgFrameRow::attX2::get() {
    return (cli::safe_cast<::System::Single >(this[this->tableimgFrame->attX2Column]));
}
inline System::Void dataFrame::imgFrameRow::attX2::set(System::Single value) {
    this[this->tableimgFrame->attX2Column] = value;
}

inline System::Single dataFrame::imgFrameRow::attY2::get() {
    return (cli::safe_cast<::System::Single >(this[this->tableimgFrame->attY2Column]));
}
inline System::Void dataFrame::imgFrameRow::attY2::set(System::Single value) {
    this[this->tableimgFrame->attY2Column] = value;
}

inline System::Boolean dataFrame::imgFrameRow::enBreak::get() {
    return (cli::safe_cast<::System::Boolean >(this[this->tableimgFrame->enBreakColumn]));
}
inline System::Void dataFrame::imgFrameRow::enBreak::set(System::Boolean value) {
    this[this->tableimgFrame->enBreakColumn] = value;
}

inline System::Boolean dataFrame::imgFrameRow::enChain::get() {
    return (cli::safe_cast<::System::Boolean >(this[this->tableimgFrame->enChainColumn]));
}
inline System::Void dataFrame::imgFrameRow::enChain::set(System::Boolean value) {
    this[this->tableimgFrame->enChainColumn] = value;
}

inline System::Int32 dataFrame::imgFrameRow::chain1::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableimgFrame->chain1Column]));
}
inline System::Void dataFrame::imgFrameRow::chain1::set(System::Int32 value) {
    this[this->tableimgFrame->chain1Column] = value;
}

inline System::Int32 dataFrame::imgFrameRow::chain2::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableimgFrame->chain2Column]));
}
inline System::Void dataFrame::imgFrameRow::chain2::set(System::Int32 value) {
    this[this->tableimgFrame->chain2Column] = value;
}

inline System::Int32 dataFrame::imgFrameRow::time::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableimgFrame->timeColumn]));
}
inline System::Void dataFrame::imgFrameRow::time::set(System::Int32 value) {
    this[this->tableimgFrame->timeColumn] = value;
}

inline System::Int32 dataFrame::imgFrameRow::imgFrames_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableimgFrame->imgFrames_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“imgFrame”中列“imgFrames_Id”的值为 DBNull。", e));
    }
}
inline System::Void dataFrame::imgFrameRow::imgFrames_Id::set(System::Int32 value) {
    this[this->tableimgFrame->imgFrames_IdColumn] = value;
}

inline dataFrame::imgFramesRow^  dataFrame::imgFrameRow::imgFramesRow::get() {
    return (cli::safe_cast<dataFrame::imgFramesRow^  >(this->GetParentRow(this->Table->ParentRelations[L"imgFrames_imgFrame"])));
}
inline System::Void dataFrame::imgFrameRow::imgFramesRow::set(dataFrame::imgFramesRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"imgFrames_imgFrame"]);
}

inline ::System::Boolean dataFrame::imgFrameRow::IsimgFrames_IdNull() {
    return this->IsNull(this->tableimgFrame->imgFrames_IdColumn);
}

inline ::System::Void dataFrame::imgFrameRow::SetimgFrames_IdNull() {
    this[this->tableimgFrame->imgFrames_IdColumn] = ::System::Convert::DBNull;
}


inline dataFrame::SkillsRow::SkillsRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableSkills = (cli::safe_cast<dataFrame::SkillsDataTable^  >(this->Table));
}

inline System::Int32 dataFrame::SkillsRow::Skills_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableSkills->Skills_IdColumn]));
}
inline System::Void dataFrame::SkillsRow::Skills_Id::set(System::Int32 value) {
    this[this->tableSkills->Skills_IdColumn] = value;
}

inline System::Int32 dataFrame::SkillsRow::Player_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableSkills->Player_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“Skills”中列“Player_Id”的值为 DBNull。", e));
    }
}
inline System::Void dataFrame::SkillsRow::Player_Id::set(System::Int32 value) {
    this[this->tableSkills->Player_IdColumn] = value;
}

inline dataFrame::PlayerRow^  dataFrame::SkillsRow::PlayerRow::get() {
    return (cli::safe_cast<dataFrame::PlayerRow^  >(this->GetParentRow(this->Table->ParentRelations[L"Player_Skills"])));
}
inline System::Void dataFrame::SkillsRow::PlayerRow::set(dataFrame::PlayerRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"Player_Skills"]);
}

inline ::System::Boolean dataFrame::SkillsRow::IsPlayer_IdNull() {
    return this->IsNull(this->tableSkills->Player_IdColumn);
}

inline ::System::Void dataFrame::SkillsRow::SetPlayer_IdNull() {
    this[this->tableSkills->Player_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< dataFrame::SkillRow^  >^  dataFrame::SkillsRow::GetSkillRows() {
    if (this->Table->ChildRelations[L"Skills_Skill"] == nullptr) {
        return gcnew cli::array< dataFrame::SkillRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< dataFrame::SkillRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"Skills_Skill"])));
    }
}


inline dataFrame::SkillRow::SkillRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tableSkill = (cli::safe_cast<dataFrame::SkillDataTable^  >(this->Table));
}

inline System::Int32 dataFrame::SkillRow::id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableSkill->idColumn]));
}
inline System::Void dataFrame::SkillRow::id::set(System::Int32 value) {
    this[this->tableSkill->idColumn] = value;
}

inline System::String^  dataFrame::SkillRow::name::get() {
    return (cli::safe_cast<::System::String^  >(this[this->tableSkill->nameColumn]));
}
inline System::Void dataFrame::SkillRow::name::set(System::String^  value) {
    this[this->tableSkill->nameColumn] = value;
}

inline System::String^  dataFrame::SkillRow::key::get() {
    return (cli::safe_cast<::System::String^  >(this[this->tableSkill->keyColumn]));
}
inline System::Void dataFrame::SkillRow::key::set(System::String^  value) {
    this[this->tableSkill->keyColumn] = value;
}

inline System::Int32 dataFrame::SkillRow::Skill_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tableSkill->Skill_IdColumn]));
}
inline System::Void dataFrame::SkillRow::Skill_Id::set(System::Int32 value) {
    this[this->tableSkill->Skill_IdColumn] = value;
}

inline System::Int32 dataFrame::SkillRow::Skills_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tableSkill->Skills_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“Skill”中列“Skills_Id”的值为 DBNull。", e));
    }
}
inline System::Void dataFrame::SkillRow::Skills_Id::set(System::Int32 value) {
    this[this->tableSkill->Skills_IdColumn] = value;
}

inline dataFrame::SkillsRow^  dataFrame::SkillRow::SkillsRow::get() {
    return (cli::safe_cast<dataFrame::SkillsRow^  >(this->GetParentRow(this->Table->ParentRelations[L"Skills_Skill"])));
}
inline System::Void dataFrame::SkillRow::SkillsRow::set(dataFrame::SkillsRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"Skills_Skill"]);
}

inline ::System::Boolean dataFrame::SkillRow::IsSkills_IdNull() {
    return this->IsNull(this->tableSkill->Skills_IdColumn);
}

inline ::System::Void dataFrame::SkillRow::SetSkills_IdNull() {
    this[this->tableSkill->Skills_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< dataFrame::imgFramesRow^  >^  dataFrame::SkillRow::GetimgFramesRows() {
    if (this->Table->ChildRelations[L"Skill_imgFrames"] == nullptr) {
        return gcnew cli::array< dataFrame::imgFramesRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< dataFrame::imgFramesRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"Skill_imgFrames"])));
    }
}


inline dataFrame::PlayersRow::PlayersRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tablePlayers = (cli::safe_cast<dataFrame::PlayersDataTable^  >(this->Table));
}

inline System::Int32 dataFrame::PlayersRow::Players_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablePlayers->Players_IdColumn]));
}
inline System::Void dataFrame::PlayersRow::Players_Id::set(System::Int32 value) {
    this[this->tablePlayers->Players_IdColumn] = value;
}

inline cli::array< dataFrame::PlayerRow^  >^  dataFrame::PlayersRow::GetPlayerRows() {
    if (this->Table->ChildRelations[L"Players_Player"] == nullptr) {
        return gcnew cli::array< dataFrame::PlayerRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< dataFrame::PlayerRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"Players_Player"])));
    }
}


inline dataFrame::PlayerRow::PlayerRow(::System::Data::DataRowBuilder^  rb) : 
        ::System::Data::DataRow(rb) {
    this->tablePlayer = (cli::safe_cast<dataFrame::PlayerDataTable^  >(this->Table));
}

inline System::Int32 dataFrame::PlayerRow::id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablePlayer->idColumn]));
}
inline System::Void dataFrame::PlayerRow::id::set(System::Int32 value) {
    this[this->tablePlayer->idColumn] = value;
}

inline System::String^  dataFrame::PlayerRow::name::get() {
    return (cli::safe_cast<::System::String^  >(this[this->tablePlayer->nameColumn]));
}
inline System::Void dataFrame::PlayerRow::name::set(System::String^  value) {
    this[this->tablePlayer->nameColumn] = value;
}

inline System::String^  dataFrame::PlayerRow::headImgPath::get() {
    return (cli::safe_cast<::System::String^  >(this[this->tablePlayer->headImgPathColumn]));
}
inline System::Void dataFrame::PlayerRow::headImgPath::set(System::String^  value) {
    this[this->tablePlayer->headImgPathColumn] = value;
}

inline System::Int32 dataFrame::PlayerRow::imgX1::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablePlayer->imgX1Column]));
}
inline System::Void dataFrame::PlayerRow::imgX1::set(System::Int32 value) {
    this[this->tablePlayer->imgX1Column] = value;
}

inline System::Int32 dataFrame::PlayerRow::imgY1::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablePlayer->imgY1Column]));
}
inline System::Void dataFrame::PlayerRow::imgY1::set(System::Int32 value) {
    this[this->tablePlayer->imgY1Column] = value;
}

inline System::Int32 dataFrame::PlayerRow::imgX2::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablePlayer->imgX2Column]));
}
inline System::Void dataFrame::PlayerRow::imgX2::set(System::Int32 value) {
    this[this->tablePlayer->imgX2Column] = value;
}

inline System::Int32 dataFrame::PlayerRow::imgY2::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablePlayer->imgY2Column]));
}
inline System::Void dataFrame::PlayerRow::imgY2::set(System::Int32 value) {
    this[this->tablePlayer->imgY2Column] = value;
}

inline System::Int32 dataFrame::PlayerRow::Player_Id::get() {
    return (cli::safe_cast<::System::Int32 >(this[this->tablePlayer->Player_IdColumn]));
}
inline System::Void dataFrame::PlayerRow::Player_Id::set(System::Int32 value) {
    this[this->tablePlayer->Player_IdColumn] = value;
}

inline System::Int32 dataFrame::PlayerRow::Players_Id::get() {
    try {
        return (cli::safe_cast<::System::Int32 >(this[this->tablePlayer->Players_IdColumn]));
    }
    catch (::System::InvalidCastException^ e) {
        throw (gcnew ::System::Data::StrongTypingException(L"表“Player”中列“Players_Id”的值为 DBNull。", e));
    }
}
inline System::Void dataFrame::PlayerRow::Players_Id::set(System::Int32 value) {
    this[this->tablePlayer->Players_IdColumn] = value;
}

inline dataFrame::PlayersRow^  dataFrame::PlayerRow::PlayersRow::get() {
    return (cli::safe_cast<dataFrame::PlayersRow^  >(this->GetParentRow(this->Table->ParentRelations[L"Players_Player"])));
}
inline System::Void dataFrame::PlayerRow::PlayersRow::set(dataFrame::PlayersRow^  value) {
    this->SetParentRow(value, this->Table->ParentRelations[L"Players_Player"]);
}

inline ::System::Boolean dataFrame::PlayerRow::IsPlayers_IdNull() {
    return this->IsNull(this->tablePlayer->Players_IdColumn);
}

inline ::System::Void dataFrame::PlayerRow::SetPlayers_IdNull() {
    this[this->tablePlayer->Players_IdColumn] = ::System::Convert::DBNull;
}

inline cli::array< dataFrame::SkillsRow^  >^  dataFrame::PlayerRow::GetSkillsRows() {
    if (this->Table->ChildRelations[L"Player_Skills"] == nullptr) {
        return gcnew cli::array< dataFrame::SkillsRow^  >(0);
    }
    else {
        return (cli::safe_cast<cli::array< dataFrame::SkillsRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"Player_Skills"])));
    }
}


inline dataFrame::imgFramesRowChangeEvent::imgFramesRowChangeEvent(dataFrame::imgFramesRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline dataFrame::imgFramesRow^  dataFrame::imgFramesRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction dataFrame::imgFramesRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline dataFrame::imgFrameRowChangeEvent::imgFrameRowChangeEvent(dataFrame::imgFrameRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline dataFrame::imgFrameRow^  dataFrame::imgFrameRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction dataFrame::imgFrameRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline dataFrame::SkillsRowChangeEvent::SkillsRowChangeEvent(dataFrame::SkillsRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline dataFrame::SkillsRow^  dataFrame::SkillsRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction dataFrame::SkillsRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline dataFrame::SkillRowChangeEvent::SkillRowChangeEvent(dataFrame::SkillRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline dataFrame::SkillRow^  dataFrame::SkillRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction dataFrame::SkillRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline dataFrame::PlayersRowChangeEvent::PlayersRowChangeEvent(dataFrame::PlayersRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline dataFrame::PlayersRow^  dataFrame::PlayersRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction dataFrame::PlayersRowChangeEvent::Action::get() {
    return this->eventAction;
}


inline dataFrame::PlayerRowChangeEvent::PlayerRowChangeEvent(dataFrame::PlayerRow^  row, ::System::Data::DataRowAction action) {
    this->eventRow = row;
    this->eventAction = action;
}

inline dataFrame::PlayerRow^  dataFrame::PlayerRowChangeEvent::Row::get() {
    return this->eventRow;
}

inline ::System::Data::DataRowAction dataFrame::PlayerRowChangeEvent::Action::get() {
    return this->eventAction;
}
