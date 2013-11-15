Notes on building the stand-alone reader.

1. When trying to link with only MacWin and Utils, EqualTol came up as an unresolved external, so someone must be including Tol.h or something at the wrong level.

2. Text.cpp in Model includes BaseApp/BaseAppServices.h.  It is calling GetActiveView().  It should be restructured so that it doesn't need to call this.

3. Model/MergeController.cpp is calling AppServices::GetUndoManager() which is not defined at the Model level.

4. InstancePath.cpp and SectionPlane.cpp both reference CPickRecord which is not defined at the Model level.

5. SteStatusText should be removed from PushPullController.cpp

6. The output variable for OpenDocument should be of type IDocument rather than IDispatch.

7. Need Mac implementations of OpenDocument and CloseDocument.
(added in special reader version of XApplication.cpp)

8. OpenDocument and CloseDocument are not implemented in the standard version of XApplicaiton.  I have copied XAxpplication to the Reader folder so that I can implement this for the reader without changing SketchUp.  After 3.0 releases, these implementations should be merged.

9. IApplication::CloseDocument is a worthless method.  There should really be a Close method on Document instead.  Or at least CloseDocument should take an argument to tell you which document you should close.  Maybe XDocument should delete the CSketchUpModel if it was created by a call to OpenDocument?

10. Some methods still return IDispatch* rather than the real type.  For example, get_Relationships.
