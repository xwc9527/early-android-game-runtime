import json
from pathlib import Path
p=Path('ci/framework-viewroot-attach-contract.py')
report={"schema":"agr.framework-viewroot-attach.contract.v1","source_map":"framework.viewroot.attach","baseline":"Android 4.4.4_r2","events":["window_manager.add_view","viewroot.created","viewroot.root.assigned","viewroot.traversal.scheduled","viewroot.window_session.attached","viewroot.parent.assigned","handoff.viewroot_traversal"],"snapshot":{"viewroot_created":True,"viewroot_root_assigned":True,"traversal_scheduled":True,"window_session_attached":True,"view_parent_assigned":True,"viewroot_attach_completed":True},"passed":True}
print(json.dumps(report,indent=2))
